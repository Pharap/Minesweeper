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

struct SkullHash
{
	// This is actually part of the algorithm for an 'Xorshift' PRNG variant.
	// PRNG algorithms that have a single-value state can be easily repurposed as hash functions.
	// The shift values are taken from page 4 of George Marsaglia's 'Xorshift RNGs'.
	// Marsaglia's 'Xorshift RNGs': https://www.jstatsoft.org/article/view/v008i14.
	// The original paper uses a CC BY 3.0 licence (https://creativecommons.org/licenses/by/3.0/).
	// This function was written from scratch, not based on any existing code, thus there is no conflict of licence.
	static uint32_t hash(uint32_t value)
	{
		value ^= (value << 13);
		value ^= (value >> 17);
		value ^= (value << 5);
		return value;
	}
};