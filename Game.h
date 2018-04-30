#pragma once

/*
Copyright (C) 2018 Pharap (@Pharap)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "GameContext.h"
#include "GameStateType.h"
#include "GameState.h"
#include "GameStateMachine.h"

class Game : public GameStateMachine<GameContext, GameStateType>
{
private:
	Context context;
	State * currentState;
	StateId currentStateId;
	StateId nextStateId;
	bool changePending;
	
public:
	void setup(void);
	void loop(void);

	Context & getContext(void) override;
	const Context & getContext(void) const override;

	void changeState(const StateId & stateId) override;

private:
	static State * createState(const StateId & stateType);

};