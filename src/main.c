/**
 * Copyright (c) 2019 Jan Siebert
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */

#include "system.h"
#include "game.h"
#include "sprites.h"

static GameState *state;

// _init is called from JavaScript when the WebAssembly-Module was loaded.
EXPORT void _init() {
	SystemConfiguration cfg;
	
	cfg.palette = (uint32_t *)vga_colors;
	cfg.spritemem = SPRITE_DATA;
	cfg.sprite_w = 128;
	cfg.sprite_h = 32;
	
	system_init(&cfg);
	state = game_init();
}


// _update is called from JavaScript 30 times per second.
// It updates the game logic and the pixelbuffer.
EXPORT void _update() {
	game_update(state);
}