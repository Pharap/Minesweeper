#include "Tile.h"

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

bool Tile::isMine() const
{
	return (this->value & isMineMask) != 0;
}

bool Tile::isVisible() const
{
	return (this->value & isVisibleMask) != 0;
}

bool Tile::isMarked() const
{
	return (this->value & isMarkedMask) != 0;
}

uint8_t Tile::getMineCount() const
{
	return (this->value & MineCountMask);	
}
	
void Tile::setIsMine(const bool & isMine)
{
	this->value = (isMine) ? (this->value | isMineMask) : (this->value & ~isMineMask);
}

void Tile::setIsVisible(const bool & isVisible)
{
	this->value = (isVisible) ? (this->value | isVisibleMask) : (this->value & ~isVisibleMask);
}

void Tile::setIsMarked(const bool & isMarked)
{
	this->value = (isMarked) ? (this->value | isMarkedMask) : (this->value & ~isMarkedMask);
}

void Tile::setMineCount(const uint8_t & mineCount)
{
	this->value &= ~MineCountMask;
	this->value |= (mineCount & MineCountMask);
}

void Tile::show()
{
	this->value |= isVisibleMask;
}
	
void Tile::hide()
{
	this->value &= ~isVisibleMask;
}
	
void Tile::mark()
{
	this->value |= isMarkedMask;
}
	
void Tile::unmark()
{
	this->value &= ~isMarkedMask;
}

void Tile::toggleMark()
{
	this->value ^= isMarkedMask;
}
