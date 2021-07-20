#pragma once

//
// Copyright (C) 2018 Pharap (@Pharap)
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

// For uint8_t
#include <stdint.h>

//
// Icons created by Vampirics (https://github.com/vampirics)
//

namespace Images
{
	constexpr uint8_t IconWidth = 28;
	constexpr uint8_t IconHeight = 28;

	constexpr uint8_t Icons[] PROGMEM
	{
		// Dimensions
		IconWidth, IconHeight,

		// Frame 0 - Sea
		0xFF, 0x7F, 0xBF, 0xBF, 0xAF, 0x97, 0xAB, 0xD7, 0xE7, 0xF7, 0xFB, 0xFB, 0xF1, 0xFE, 0xF9, 0xFE, 0xF1, 0xFB, 0xF7, 0xE7, 0xD7, 0xAB, 0x97, 0xAF, 0xBB, 0xB5, 0x7B, 0xFF,
		0xBF, 0x5E, 0xA1, 0xFE, 0xBF, 0xFF, 0xBF, 0xF9, 0xD6, 0x56, 0x49, 0x6E, 0x71, 0x7F, 0xFF, 0x7F, 0x71, 0x4E, 0x59, 0x56, 0xF6, 0xB9, 0xFF, 0xBF, 0xFE, 0xA1, 0x5E, 0xBF,
		0xFF, 0xF3, 0xEC, 0xE9, 0x57, 0x9F, 0x7F, 0xCF, 0xB5, 0xB5, 0xC9, 0xBB, 0xC7, 0xFF, 0xFF, 0xFF, 0xC7, 0xBB, 0xC9, 0x35, 0xB5, 0x4F, 0x9F, 0x57, 0xE9, 0xEC, 0xF3, 0xFF,
		0x0F, 0x0D, 0x0A, 0x0D, 0x0F, 0x0E, 0x0D, 0x0E, 0x0E, 0x0E, 0x0D, 0x0D, 0x09, 0x06, 0x09, 0x06, 0x09, 0x0D, 0x0E, 0x0E, 0x0E, 0x0D, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,

		// Frame 1 - Land
		0xFF, 0x5F, 0xA7, 0x47, 0xC7, 0x8B, 0x9F, 0x9B, 0x93, 0x93, 0x93, 0x93, 0x9B, 0x9F, 0x8B, 0xC7, 0xC7, 0xA7, 0x8F, 0xFF, 0xFF, 0xEF, 0xF7, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFE, 0xBD, 0xD8, 0xB8, 0xF8, 0xF8, 0xF8, 0xD6, 0xA9, 0x51, 0x31, 0x22, 0x27, 0x26, 0x24, 0x24, 0x24, 0x24, 0x26, 0x27, 0x22, 0x11, 0x11, 0x09, 0x83, 0xFF,
		0xFF, 0xAF, 0x53, 0xA3, 0x63, 0x45, 0x4F, 0x4D, 0x49, 0x49, 0x49, 0x49, 0x4D, 0x4F, 0x45, 0x22, 0x22, 0x12, 0x06, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xEE, 0xFF, 0xFF, 0xFF,
		0x0F, 0x0F, 0x0F, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0D, 0x0E, 0x0D, 0x0F, 0x0F, 0x0F,

		// Frame 2 - Turtle
		0xFF, 0x87, 0x7B, 0xF5, 0xDD, 0xAD, 0xDD, 0xF5, 0x7B, 0xF3, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0xBF, 0xDF, 0xDF, 0xDF, 0xDF,
		0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFC, 0x80, 0x2A, 0x57, 0xFE, 0xE0, 0x1F, 0x7F, 0x9F, 0xCF, 0xE7, 0xFB, 0xFB, 0xFD, 0xFC, 0xFE, 0xF8, 0xF6, 0xF5, 0xF5, 0xF5, 0xF5,
		0xDF, 0xBF, 0xBF, 0xDF, 0xDF, 0xBF, 0xBF, 0xDF, 0xDC, 0xF1, 0xE4, 0xC3, 0x18, 0x9E, 0xBF, 0xBF, 0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
		0x0F, 0x0F, 0x0A, 0x0D, 0x0F, 0x0F, 0x0A, 0x0D, 0x0F, 0x0F, 0x0B, 0x08, 0x09, 0x09, 0x09, 0x09, 0x08, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,

		// Frame 3 - Cactus
		0xE5, 0xEB, 0x68, 0xE7, 0xE8, 0x01, 0xFD, 0xFC, 0x1D, 0x1C, 0x1D, 0x1D, 0xFC, 0xFD, 0xFC, 0x1D, 0x1D, 0x1C, 0x1D, 0xFC, 0xFD, 0x01, 0xEA, 0x01, 0x7C, 0x7D, 0x00, 0xED,
		0xFF, 0x7E, 0xBF, 0x7E, 0xFF, 0x00, 0xFF, 0xFF, 0xFE, 0xFE, 0x02, 0x02, 0xC1, 0xC1, 0xC1, 0x02, 0x02, 0xFE, 0xFE, 0xFF, 0xFF, 0x00, 0xFF, 0xB8, 0xDB, 0xBB, 0xF8, 0xFF,
		0xFF, 0xFF, 0xEF, 0xF7, 0xEF, 0xFF, 0x00, 0xFE, 0xFE, 0xFE, 0x00, 0xFE, 0xAA, 0x56, 0xAA, 0x56, 0xAA, 0x56, 0xAA, 0x56, 0xFE, 0x00, 0xFF, 0xFF, 0xFB, 0xFD, 0xFB, 0xFF,
		0x0F, 0x0B, 0x0D, 0x0B, 0x0F, 0x0F, 0x0E, 0x01, 0x0F, 0x0F, 0x0C, 0x03, 0x0E, 0x05, 0x0A, 0x05, 0x0A, 0x05, 0x0A, 0x05, 0x0F, 0x00, 0x0F, 0x0D, 0x0E, 0x0D, 0x0F, 0x0F,

		// Frame 4 - Penguin
		0xBF, 0x5F, 0x1F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x01, 0x81, 0xF9, 0x7F, 0xBF, 0x5F, 0x1F, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0x7A, 0x7D, 0x7C, 0x7D, 0x78, 0xF0, 0xE0, 0xC0, 0xC0, 0x80, 0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x01,
		0x00, 0x00, 0x00, 0x01, 0x81, 0x9D, 0x3A, 0x3A, 0x3B, 0x7B, 0x73, 0x77, 0x77, 0x72, 0x79, 0x78, 0x78, 0x38, 0x38, 0x94, 0xCE, 0xCF, 0xDE, 0x3E, 0xBC, 0xFA, 0xF2, 0xE2,
		0x0E, 0x0E, 0x08, 0x01, 0x07, 0x0F, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x06, 0x06, 0x06, 0x07, 0x03, 0x0B, 0x01, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x00,
	};
}