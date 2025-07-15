#pragma once

#include <iostream>

class BigObject
{
public:

	BigObject()
	{
		std::cout << "Constructor: Allocating a lot of memory\n";
	}

	~BigObject()
	{
		std::cout << "Destructor : Releasing a lot of memory\n";
	}

	BigObject(const BigObject& other)
	{
		std::cout << "Copy Constructor: Copying a lot of memory\n";
	}

	BigObject& operator = (const BigObject& other)
	{
		std::cout << "Assignment operator : Copying a lot of memory\n";
		return *this;
	}
};
