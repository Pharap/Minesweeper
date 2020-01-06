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

#include <stddef.h>
#include <stdint.h>

#include "Utils.h"

template< typename TChecksum, size_t EeepromCapacityValue, uintptr_t SaveStartValue, typename TData >
class SaveSystem
{
public:
	SaveSystem() = delete;

public:
	using ChecksumType = TChecksum;
	using DataType = TData;
	
	struct Header
	{
		uint32_t checksum;
		uint16_t dataSize;
	};

	struct SaveBlock
	{
		Header header;
		DataType data;
	};

public:
	static constexpr size_t EepromCapacity = EeepromCapacityValue;

	static constexpr uintptr_t SaveStart = SaveStartValue;
	static constexpr size_t SaveSize = sizeof(SaveBlock);

	static constexpr uintptr_t HeaderStart = SaveStart;
	static constexpr size_t HeaderSize = sizeof(Header);
	
	static constexpr uintptr_t ChecksumStart = SaveStart;
	static constexpr size_t ChecksumSize = sizeof(uint32_t);

	static constexpr uintptr_t DataSizeStart = ChecksumStart + ChecksumSize;
	static constexpr size_t DataSizeSize = sizeof(uint16_t);

	static constexpr uintptr_t DataStart = DataSizeStart + DataSizeSize;
	static constexpr size_t DataSize = sizeof(DataType);

	static_assert(SaveSize <= EepromCapacity, "Save size is larger than the EEPROM capacity");
	static_assert(SaveStart + SaveSize <= EepromCapacity, "The save size can't fit at the provided offset");

public:
	// Initialise the save data when there's no save file
	static void initialise(const DataType & data)
	{
		SaveBlock saveBlock;

		saveBlock.data = data;
		saveBlock.header.dataSize = DataSize;
		saveBlock.header.checksum = ChecksumType::calculateChecksum(saveBlock.data);

		Eeprom::update(SaveStart, saveBlock);
	}

	// Calculate the checksum from the data in EEPROM
	static uint32_t calculateChecksum(char * buffer, size_t size)
	{
		const size_t dataSize = static_cast<size_t>(Eeprom::read<uint16_t>(DataSizeStart));

		if(size < dataSize)
			return 0;

		Eeprom::read(DataStart, buffer, dataSize);

		return ChecksumType::calculateChecksum(buffer, dataSize);
	}

	template< size_t size >
	static uint32_t calculateChecksum(char (&buffer)[size])
	{
		return calculateChecksum(buffer, size);
	}

	template< size_t size >
	static uint32_t calculateChecksum(unsigned char (&buffer)[size])
	{
		return calculateChecksum(reinterpret_cast<char *>(buffer), size);
	}

	template< size_t size >
	static uint32_t calculateChecksum(signed char (&buffer)[size])
	{
		return calculateChecksum(reinterpret_cast<char *>(buffer), size);
	}

	// Verify the file checksum
	static bool verifyChecksum(char * buffer, size_t size)
	{
		const size_t dataSize = static_cast<size_t>(Eeprom::read<uint16_t>(DataSizeStart));

		if(size < dataSize)
			return false;

		Eeprom::read(DataStart, buffer, dataSize);

		const uint32_t checksum = ChecksumType::calculateChecksum(buffer, dataSize);
		const uint32_t savedChecksum = Eeprom::read<uint32_t>(ChecksumStart);

		return (savedChecksum == checksum);
	}

	template< size_t size >
	static bool verifyChecksum(char (&buffer)[size])
	{
		return verifyChecksum(buffer, size);
	}

	template< size_t size >
	static bool verifyChecksum(unsigned char (&buffer)[size])
	{
		return verifyChecksum(reinterpret_cast<char *>(buffer), size);
	}

	template< size_t size >
	static bool verifyChecksum(signed char (&buffer)[size])
	{
		return verifyChecksum(reinterpret_cast<char *>(buffer), size);
	}

	// Load the data
	static DataType loadData()
	{
		const size_t dataSize = static_cast<size_t>(Eeprom::read<uint16_t>(DataSizeStart));
		const size_t limit = (dataSize < DataSize) ? dataSize : DataSize;

		DataType data;
		char * dataBuffer = reinterpret_cast<char *>(&data);
		Eeprom::read<char>(DataStart, dataBuffer, limit);
		return data;
	}

	// Save the data block and update the checksum
	// using the data size from the save file
	static void saveData(const DataType & data, char * buffer, size_t size)
	{
		Eeprom::update(DataStart, data);

		size_t dataSize = static_cast<size_t>(Eeprom::read<uint16_t>(DataSizeStart));
		if(dataSize < DataSize)
		{
			dataSize = DataSize;
			Eeprom::update(DataSizeStart, DataSize);
		}

		if(size < dataSize)
			return;

		Eeprom::read(DataStart, buffer, dataSize);

		const uint32_t checksum = ChecksumType::calculateChecksum(buffer, dataSize);

		Eeprom::update(ChecksumStart, checksum);
	}

	template< size_t size >
	static void saveData(const DataType & data, char (&buffer)[size])
	{
		saveData(data, buffer, size);
	}

	template< size_t size >
	static void saveData(const DataType & data, signed char (&buffer)[size])
	{
		saveData(data, reinterpret_cast<char *>(buffer), size);
	}

	template< size_t size >
	static void saveData(const DataType & data, unsigned char (&buffer)[size])
	{
		saveData(data, reinterpret_cast<char *>(buffer), size);
	}
};