#include <iostream>
#include <vector>

using namespace std;

void UsingIterator()
{
	// using initializer_list
	vector<int> vec{ 0, 1, 2 };

	cout << "Using iterator" << "\n";

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << "\n";
	}
}

void UsingIteratorWithAuto()
{
	vector<int> vec{ 0, 1, 2 };

	cout << "Using iterator with auto" << "\n";

	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << "\n";
	}
}

void UsingRangeBasedLoop()
{
	vector<int> vec{ 0, 1, 2 };

	cout << "Using range based loop" << "\n";

	for (int i : vec)
	{
		cout << i << "\n";
	}
}

void RangeBasedLoop()
{
	UsingIterator();
	UsingIteratorWithAuto();
	UsingRangeBasedLoop();
}
