#include "Array.hpp"
#include <iostream>


namespace Module1
{
	using std::cin;
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

	void BoundsChecking()
	{
		try {
			IntArray arr{ 10 };
			for (int i = 0; i < arr.Size(); i++) {
				arr[i] = (i + 1) * 10;
			}

			cout << "Array elements: ";
			for (int i = 0; i < arr.Size(); i++) {
				cout << arr[i] << ' ';
			}

			cout << "Array size is" << arr.Size() << endl;
			cout << "Please enter an array index: ";
			int index{};
			cin >> index;

			cout << "The element at index " << index << " is " << arr[index] << endl;
		}
		catch (const IndexOutOfBoundsException& e) {
			cout << endl << "*** ERROR: Invalid array index!" << endl;
		}
	}
}
int main()
{
	//Module1::FirstSample();
	//Module1::AccessingElements();
	Module1::BoundsChecking();
}
