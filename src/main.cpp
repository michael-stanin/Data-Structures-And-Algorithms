#include "Array.hpp"
#include <iostream>
#include <cassert>

namespace Module1
{
	using std::cin;
	using std::cout;
	using std::endl;

	void FirstSample()
	{
		cout << "Creating an empty array." << endl;
		Array<int> a{};
		cout << "a.Size() is " << a.Size() << endl;
		assert(a.IsEmpty());
		assert(a.Size() == 0);

		cout << "-------------------------------------------" << endl;

		cout << "Creating an array containing 10 elements" << endl;
		Array<int> b{ 10 };
		cout << "b.Size() is " << b.Size() << endl;
		assert(!b.IsEmpty());
	}

	void AccessingElements()
	{
		Array<int> arr{ 3 };
		cout << "Setting arr[0] = 10" << endl;
		arr[0] = 10;
		cout << "arr[0] is " << arr[0] << endl;
	}

	void BoundsChecking()
	{
		try {
			Array<int> arr{ 10 };
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
		catch (const IndexOutOfBoundsException&) {
			cout << endl << "*** ERROR: Invalid array index!" << endl;
		}
	}
}

namespace Module2
{
	using std::cout;
	using std::endl;

	void ConvinientlyPrintArrays()
	{
		Array<int> arr{10};
		for (int i = 0; i < arr.Size(); i++) {
			arr[i] = (i+1)*10;
		}

		cout << "Array elements : " << arr << endl;
	}

	void SubtleBugWhenCopyingArray()
	{
		Array<int> a{3};
		a[0] = 10;
		a[1] = 20;
		a[2] = 30;

		Array<int> b = a;

		cout << "a = " << a << endl;
		cout << "b = " << b << endl;

		b[1] = 100;
		cout << endl << "b[1] = 100;" << endl << endl;

		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}
}

int main()
{
	//Module1::FirstSample();
	//Module1::AccessingElements();
	//Module1::BoundsChecking();
	//Module2::ConvinientlyPrintArrays();
	Module2::SubtleBugWhenCopyingArray();
}
