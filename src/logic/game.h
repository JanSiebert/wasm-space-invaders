/**
 * Copyright (c) 2019 Jan Siebert
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */

/*

                         _    _  ___   ________  ___                               
                        | |  | |/ _ \ /  ___|  \/  |                               
                        | |  | / /_\ \\ `--.| .  . |                               
                        | |/\| |  _  | `--. \ |\/| |                               
                        \  /\  / | | |/\__/ / |  | |                               
                         \/  \/\_| |_/\____/\_|  |_/                               
                                                                                   
                                                                                   
 ___________  ___  _____  _____   _____ _   _ _   _  ___ ______ ___________  _____ 
/  ___| ___ \/ _ \/  __ \|  ___| |_   _| \ | | | | |/ _ \|  _  \  ___| ___ \/  ___|
\ `--.| |_/ / /_\ \ /  \/| |__     | | |  \| | | | / /_\ \ | | | |__ | |_/ /\ `--. 
 `--. \  __/|  _  | |    |  __|    | | | . ` | | | |  _  | | | |  __||    /  `--. \
/\__/ / |   | | | | \__/\| |___   _| |_| |\  \ \_/ / | | | |/ /| |___| |\ \ /\__/ /
\____/\_|   \_| |_/\____/\____/   \___/\_| \_/\___/\_| |_/___/ \____/\_| \_|\____/ 
                                                                                   
                                                                                   

*/

#pragma once
#include "system.h"

#define STATUS_BAR_HEIGHT LETTER_HEIGHT + 4 + 1
#define MAX_OBJECTS 512
typedef struct _GameState GameState;

// The Game has 4 scenes
#define SCENE_MAINMENU 1
#define SCENE_WAVE 2
#define SCENE_BOSS 3
#define SCENE_GAMEOVER 4

#include "game_object.h"
#include "game_player.h"
#include "game_alien.h"

struct _GameState {
	struct _GameObject objects[MAX_OBJECTS];
	int score;
	int wave; // <- correlated with difficulty
	int alien_counter; // <- the boss-ufo will show up, if this is 0
	int scene;
	int next_scene;
	uint64_t scene_ticks;
	GameObject *player;
};

GameState *game_init();
void game_update(GameState *state);



