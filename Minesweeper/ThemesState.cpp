#include "ThemesState.h"

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

#include "Images.h"
#include "Languages.h"

#include "Utils.h"

void ThemesState::update(StateMachine & machine)
{
	auto & arduboy = machine.getContext().arduboy;
	
	if (arduboy.justPressed(Arduboy::ButtonB))
	{
		machine.changeState(GameStateType::TitleScreen);
	}
	
	if (arduboy.justPressed(Arduboy::ButtonLeft))
	{
		if (Context::mineType > Context::FirstMineType)
			--Context::mineType;
	}

	if (arduboy.justPressed(Arduboy::ButtonRight))
	{
		if (Context::mineType < Context::LastMineType)
			++Context::mineType;
	}
}

void ThemesState::render(StateMachine & machine)
{
	auto & arduboy = machine.getContext().arduboy;

	// Draw the state title "themes"
	{
		constexpr uint8_t x = CalculateCentreX(StringWidth(Strings::Themes));
		constexpr uint8_t y = 4;

		arduboy.setCursor(x, y);
		arduboy.print(AsFlashString(Strings::Themes));
	}

	// Draw mine selector
	{
		constexpr uint8_t singleMargin = 2;
		constexpr uint8_t doubleMargin = singleMargin * 2;

		constexpr uint8_t x = CalculateCentreX(Images::LargeTileFrameWidth);
		constexpr uint8_t y = CalculateCentreY(Images::LargeTileFrameHeight);

		arduboy.drawRect(x - singleMargin, y - singleMargin, Images::LargeTileFrameWidth + doubleMargin, Images::LargeTileFrameHeight + doubleMargin, Arduboy::ColourWhite);

		const uint8_t index = (12 + Context::mineType);
		Sprites::drawOverwrite(x, y, Images::LargeTiles, index);

		constexpr uint8_t leftArrowX = x - (Images::ArrowWidth + singleMargin);
		constexpr uint8_t rightArrowX = x + (Images::LargeTileFrameWidth + singleMargin);

		constexpr uint8_t arrowY = y + CalculateCentre(Images::LargeTileFrameHeight, Images::ArrowHeight);

		if (Context::mineType > Context::FirstMineType)
		{
			Sprites::drawOverwrite(leftArrowX, arrowY, Images::Arrows, 2);
		}

		if (Context::mineType < Context::LastMineType)
		{
			Sprites::drawOverwrite(rightArrowX, arrowY, Images::Arrows, 3);
		}
	}
}