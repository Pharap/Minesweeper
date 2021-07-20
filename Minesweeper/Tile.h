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

#include <stdint.h>

class Tile
{
private:
	static constexpr uint8_t isMineMask = 1 << 4;
	static constexpr uint8_t isVisibleMask = 1 << 5;
	static constexpr uint8_t isMarkedMask = 1 << 6;
	static constexpr uint8_t MineCountMask = 0x0F;

private:
	uint8_t value;

public:
	bool isMine() const;
	bool isVisible() const;
	bool isMarked() const;
	uint8_t getMineCount() const;
	
	void setIsMine(const bool & isMine);
	void setIsVisible(const bool & isVisible);
	void setIsMarked(const bool & isMarked);
	void setMineCount(const uint8_t & mineCount);

	void show();
	void hide();
	void mark();
	void unmark();
	
	void toggleMark();
};