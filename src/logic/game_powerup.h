/**
 * Copyright (c) 2019 Jan Siebert
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */

#pragma once

typedef struct _PowerUp PowerUp;
#define POWER_UP_LIVE 1
#define POWER_UP_UPGRADE 2

#include "game_object.h"

struct _PowerUp {
	int kind;
};

void game_init_powerup(GameState *state, int x, int y);