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

template< typename T, uint8_t Capacity >
class Stack
{
private:
	static constexpr uint8_t capacity = Capacity;

private:
	T items[capacity];
	uint8_t next;
	
public:
	uint8_t getCapacity() const;
	uint8_t getCount() const;
	
	bool isEmpty() const;
	bool isFull() const;
	
	const T & peek() const;
	T && pull();
	bool push(const T & item);
};


template< typename T, uint8_t Capacity >
uint8_t Stack<T, Capacity>::getCapacity() const
{
	return capacity;
}

template< typename T, uint8_t Capacity >
uint8_t Stack<T, Capacity>::getCount() const
{
	return this->next;
}

template< typename T, uint8_t Capacity >
bool Stack<T, Capacity>::isEmpty() const
{
	return (this->next == 0);
}

template< typename T, uint8_t Capacity >
bool Stack<T, Capacity>::isFull() const
{
	return (this->next == capacity);
}

template< typename T, uint8_t Capacity >
const T & Stack<T, Capacity>::peek() const
{
	return this->items[this->next - 1];
}

template< typename T, uint8_t Capacity >
T && Stack<T, Capacity>::pull()
{
	--this->next;
	return static_cast<T&&>(this->items[this->next]);
}

template< typename T, uint8_t Capacity >
bool Stack<T, Capacity>::push(const T & item)
{	
	if(this->next < capacity)
	{		
		this->items[this->next] = item;
		++this->next;
		return true;
	}
	return false;
}