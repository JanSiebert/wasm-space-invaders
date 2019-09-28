/**
 * Copyright (c) 2019 Jan Siebert
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */

#pragma once

typedef struct _Bullet Bullet;

#include "game_object.h"

struct _Bullet {
	int damage;
	double speed;
};

void game_init_player_bullet(GameState *state, int x, int y);
void game_init_alien_bullet(GameState *state, int x, int y);