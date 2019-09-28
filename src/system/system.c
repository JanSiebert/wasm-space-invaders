/**
 * Copyright (c) 2019 Jan Siebert
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */

#include "system.h"

void system_init(SystemConfiguration *configuration) {
	system_base_init();
	system_video_init(configuration);
	system_input_init();
}