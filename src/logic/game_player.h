/**
 * Copyright (c) 2019 Jan Siebert
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */

#pragma once

typedef struct _Player Player;

#include "game_object.h"

struct _Player {
	double velocity;
	void (*onCollision)(GameObject *other, GameState *state, GameObject *player);
	int level;
	int lives;
};

GameObject *game_init_player(GameState *state);
