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
}

void ThemesState::render(StateMachine & machine)
{
	auto & arduboy = machine.getContext().arduboy;

	constexpr const uint8_t step = FontCharHeight + 1;

	uint8_t y = 4;

	// Draw the title
	{
		constexpr const uint8_t width = StringWidth(Strings::Themes);
		constexpr const uint8_t x = CalculateCentreX(width);
		arduboy.setCursor(x, y);
		arduboy.print(AsFlashString(Strings::Themes));
	}
	
	// Draw a placeholder message
	{
		constexpr const uint8_t x = 4;

		y += step;
		arduboy.setCursor(x, y);
		arduboy.print(F("Coming Soon"));

		y += step;
		arduboy.setCursor(x, y);
		arduboy.print(F("Please press B"));
		
		y += step;
		arduboy.setCursor(x, y);
		arduboy.print(F("to go back"));
	}
}