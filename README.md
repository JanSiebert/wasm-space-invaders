# wasm-space-invaders
[CLICK TO PLAY](https://jansiebert.github.io/wasm-space-invaders/index.html)

I made this little game to learn about WebAssembly. The game is written in C and compiled to WebAssembly. No standard-library or emascripten-bindings are used. The basic idea is that the module allocates memory for the screen buffer. Every frame an update()-method is called from JavaScript. This updates the game state and redraws the screen buffer. JavaScript reads from this buffer and copies the data onto a canvas. Keyboard controls are mapped the other way around: Every frame JavaScript writes the current state of the keyboard to a specific location in memory. It then can be read from WebAssembly.

No standard-library is used. I was inspired by an [article by Surma](https://dassur.ma/things/c-to-webassembly/) and also implemented a *bump allocator*. This is fine for this little game. The module also contains a pseudo-random-generator and basic function to output sprites and text on the screen.

The lower level function are placed in the `system/`-folder, while the game logic can be found in the `logic/`-folder. All graphics are embedded. Script for packing the graphics can be found in the `resource/`-folder. The executable has a filesize of 12kb.

The program can be compiled inside a Docker container. The compiled game is served on port 8000.
