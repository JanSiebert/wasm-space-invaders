/**
 * Copyright (c) 2019 Jan Siebert
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */

#pragma once

typedef struct _Title Title;
#define TITLE_MAX_LENGTH 40

#include "game_object.h"

struct _Title {
	void (*next)(GameState *state);
	char text[TITLE_MAX_LENGTH+1];
	int ticks;
};

GameObject *game_init_title(GameState *state);