#include "Array.hpp"
#include <iostream>


namespace Module1
{
	using std::cout;
	using std::endl;

	void FirstSample()
	{
		cout << "Creating an empty array." << endl;
		IntArray a{};
		cout << "a.Size() is " << a.Size() << endl;
		//assert(a.IsEmpty());

		cout << "-------------------------------------------" << endl;

		cout << "Creating an array containing 10 elements" << endl;
		IntArray b{ 10 };
		cout << "b.Size() is " << b.Size() << endl;
		//assert(!b.IsEmpty());
	}

	void AccessingElements()
	{
		IntArray arr{ 3 };
		cout << "Setting arr[0] = 10" << endl;
		arr[0] = 10;
		cout << "arr[0] is " << arr[0] << endl;
	}
}
int main()
{
	//Module1::FirstSample();
	Module1::AccessingElements();

}
