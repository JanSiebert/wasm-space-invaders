FROM ubuntu:disco

RUN apt-get update && \
	apt-get install -y git python3 && \
	mkdir /build && \
	cd /build && \
	git clone https://github.com/emscripten-core/emsdk.git

RUN cd /build/emsdk && \
	./emsdk install latest && \
	./emsdk activate latest

RUN apt-get install -y libxml2-dev
RUN apt-get install -y make

COPY . /project

ENV PATH="${PATH}:/build/emsdk/fastcomp/bin"

RUN cd /project && \
	/build/emsdk/emsdk_env.sh  && \
	make

WORKDIR /project/public
EXPOSE 8000

CMD ["python3", "-m", "http.server"]
