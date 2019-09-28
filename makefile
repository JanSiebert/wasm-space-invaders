all:
	cd src && \
	clang \
	  --target=wasm32 \
	  -nostdlib \
	  -Wl,--no-entry \
	  -Wl,--strip-all \
	  -Wl,--export-dynamic \
	  -Os \
	  -fvisibility=hidden \
	  -Wl,--initial-memory=8388608 \
	  -Wl,--lto-O3 \
	  -Wl,-z,stack-size=1048576 \
	  -I ./system/ \
	  -I ./logic/ \
	  -o ../public/main.wasm \
	  main.c system/system*.c logic/game*.c