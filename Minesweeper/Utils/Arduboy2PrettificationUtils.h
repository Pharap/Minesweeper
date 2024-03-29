#pragma once

//
// Copyright (C) 2018-2021 Pharap (@Pharap)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <Arduboy2.h>

//
// Const Globals
//

namespace Arduboy
{
	constexpr uint8_t ScreenWidth = WIDTH;
	constexpr uint8_t ScreenHeight = HEIGHT;
	
	constexpr uint8_t ColourBlack = BLACK;
	constexpr uint8_t ColourWhite = WHITE;
	constexpr uint8_t ColourInvert = INVERT;

	constexpr uint8_t ButtonA = A_BUTTON;
	constexpr uint8_t ButtonB = B_BUTTON;
	constexpr uint8_t ButtonLeft = LEFT_BUTTON;
	constexpr uint8_t ButtonRight = RIGHT_BUTTON;
	constexpr uint8_t ButtonUp = UP_BUTTON;
	constexpr uint8_t ButtonDown = DOWN_BUTTON;

	constexpr uint8_t EepromStorageSpaceStart = EEPROM_STORAGE_SPACE_START;
}

// Don't have time to do the rest, I'll add them later

//
// Undefs
//

// Probably don't everywhere work yet, I'll fix this later
#undef WIDTH
#undef HEIGHT

#undef BLACK
#undef WHITE
#undef INVERT

#undef A_BUTTON
#undef B_BUTTON
#undef LEFT_BUTTON
#undef RIGHT_BUTTON
#undef UP_BUTTON
#undef DOWN_BUTTON

#undef EEPROM_STORAGE_SPACE_START