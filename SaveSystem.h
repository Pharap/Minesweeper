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

#include <stddef.h>
#include <stdint.h>

template< size_t EeepromCapacityValue, size_t SaveStartValue, typename TData >
class SaveSystem
{
public:
	SaveSystem(void) = delete;

public:
	using DataType = TData;

public:
	constexpr const static size_t EepromCapacity = EeepromCapacityValue;
	constexpr const static size_t SaveStart = SaveStartValue;

	constexpr const static size_t ChecksumStart = SaveStart;
	constexpr const static size_t ChecksumSize = sizeof(uint32_t);

	constexpr const static size_t DataStart = SaveStart + ChecksumSize;
	constexpr const static size_t DataSize = sizeof(DataType);

	constexpr const static size_t SaveSize = ChecksumSize + DataSize;

private:
	static uint32_t hash(uint32_t value)
	{
		value ^= value << 13;
		value ^= value >> 17;
		value ^= value << 5;
		return value;
	}

	template< typename T >
	static uint32_t calculateChecksum(const T & data)
	{
		return calculateChecksum(reinterpret_cast<const char *>(&data), sizeof(T));
	}

	template< size_t size >
	static uint32_t calculateChecksum(const char(&block)[size])
	{
		return calculateChecksum(block, size);
	}

	static uint32_t calculateChecksum(const char * block, size_t size)
	{
		uint32_t sum = 0;
		for (size_t i = 0; i < size; i += 4)
		{
			uint32_t value = 0;
			for (uint8_t j = 0; j < 4; ++j)
			{
				const size_t k = (i + j) % size;
				value <<= 8;
				value |= block[k];
			}
			sum = hash(sum + value);
		}
		return sum;
	}

public:
	static bool verifySave(void)
	{
		uint32_t savedChecksum;
		EEPROM.get(ChecksumStart, savedChecksum);

		DataType data;
		EEPROM.get(DataStart, data);

		uint32_t checksum = calculateChecksum(data);

		return (savedChecksum == checksum);
	}

	static DataType loadAndVerify(void)
	{
		uint32_t savedChecksum;
		EEPROM.get(ChecksumStart, savedChecksum);

		DataType data;
		EEPROM.get(DataStart, data);

		uint32_t checksum = calculateChecksum(data);

		return (savedChecksum == checksum) ? data : DataType();
	}

	static DataType load(void)
	{
		DataType data;
		EEPROM.get(DataStart, data);
		return data;
	}

	static void save(const DataType & data)
	{
		uint32_t checksum = calculateChecksum(data);
		EEPROM.put(ChecksumStart, checksum);
		EEPROM.put(DataStart, data);
	}

	static void clearSave(void)
	{
		save(DataType());
	}
};