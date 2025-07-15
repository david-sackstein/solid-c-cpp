#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Print(const vector<int>& vec)
{
	for (int i : vec)
	{
		cout << i << "\n";
	}
}

void UsingBuiltInFunctor()
{
	cout << "Using built-in functor\n";

	vector<int> vec{ 1, 2, 0 };

	sort(vec.begin(), vec.end(), less<int>());

	Print(vec);
}

void UsingCustomFunctor()
{
	struct MyLess
	{
		bool operator () (const int& lhs, const int& rhs)
		{
			return lhs > rhs;
		}
	};

	cout << "Using custom built functor\n";

	vector<int> vec{ 1, 2, 0 };

	sort(vec.begin(), vec.end(), MyLess());

	Print(vec);
}

void UsingCustomFunctorWithParameter()
{
	struct LessOrMore
	{
		LessOrMore(bool isLess) :
			_isLess(isLess)
		{
		}

		bool operator () (const int& lhs, const int& rhs)
		{
			if (_isLess)
				return lhs < rhs;
			else
				return lhs > rhs;
		}

		bool _isLess;
	};

	cout << "Using custom built functor with parameter\n";

	vector<int> vec{ 1, 2, 0 };

	sort(vec.begin(), vec.end(), LessOrMore(true));

	Print(vec);
}

void UsingLambda()
{
	cout << "Using lambda\n";

	bool isLess = false;

	auto lessOrMore = [isLess](const int& lhs, const int& rhs)
	{
		if (isLess)
			return lhs < rhs;
		else
			return lhs > rhs;
	};

	vector<int> vec{ 1, 2, 0 };

	sort(vec.begin(), vec.end(), lessOrMore);

	Print(vec);
}

void FromFunctorsToLambda()
{
	UsingBuiltInFunctor();
	UsingCustomFunctor();
	UsingCustomFunctorWithParameter();
	UsingLambda();
}
