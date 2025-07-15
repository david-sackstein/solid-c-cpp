#include "BigObject.h"
#include "BigObjectWithMove.h"

using namespace std;

template<typename T>
T CreateBigObjectWithRVO()
{
	return T();
}

template<typename T>
T CreateBigObjectWithoutRVO()
{
	T bigobject;
	return bigobject;
}

template<typename T>
void WithoutRVO()
{
	cout << "\nCreating a big object without RVO\n\n";

	T bigObject = CreateBigObjectWithoutRVO<T>();
}

template<typename T>
void WithRVO()
{
	cout << "\nCreating a big object with RVO (return value optimization)\n\n";

	T bigObject = CreateBigObjectWithRVO<T>();
}

template<typename T>
void Run()
{
	WithoutRVO<T>();
	WithRVO<T>();
}

void RValuesAndMoveSemantics()
{
	cout << "Running with BigObject\n\n";

	Run<BigObject>();
	
	cout << "Running with BigObject that has a move constructor\n\n";
	
	Run<BigObjectWithMove>();
}
