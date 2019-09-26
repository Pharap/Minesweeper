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

#include "GameContext.h"

#include "GameState.h"
#include "GameStateType.h"

class SplashScreenState : public GameState<GameContext, GameStateType>
{
private:
	static constexpr const uint8_t BlinkDelayDefault = 2;
	static constexpr const uint8_t BlinkDelayVariance = 5;
	static constexpr const uint8_t BlinkTickMin = 0;
	static constexpr const uint8_t BlinkTickMax = 7;

private:
	bool blinkInvert;
	uint8_t blinkTick;
	uint8_t blinkDelay = BlinkDelayDefault;

public:
	void activate(StateMachine & machine) override;

	void update(StateMachine & machine) override;
	void render(StateMachine & machine) override;
};