#pragma once

#include <iostream>

class BigObjectWithMove
{
public:

	BigObjectWithMove()
	{
		std::cout << "Constructor: Allocating a lot of memory\n";
	}

	~BigObjectWithMove()
	{
		std::cout << "Destructor : Releasing a lot of memory\n";
	}

	BigObjectWithMove(BigObjectWithMove&&)
	{
		std::cout << "Move Constructor: Exchanging pointers\n";
	}

	BigObjectWithMove(const BigObjectWithMove& other)
	{
		std::cout << "Copy Constructor: Copying a lot of memory\n";
	}

	BigObjectWithMove& operator = (const BigObjectWithMove& other)
	{
		std::cout << "Assignment operator : Copying a lot of memory\n";
		return *this;
	}
};
