#include "Array.hpp"
#include "List.hpp"
#include "Stack.hpp"
#include <functional>
#include <iostream>
#include <cassert>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

namespace Module1
{
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

namespace Module3
{
	using std::function;
	using std::vector;

	constexpr int kNotFound = -1;

	int LinearSearch(int element, const int* arr, int size)
	{
		// For each item in the input array,
		// compare it with the search element
		for (int i = 0; i < size; i++) {
			if (arr[i] == element) {
				// Element found!
				// Return its position to the caller
				return i;
			}
		}

		return kNotFound;
	}

	int BinarySearch(int element, const int* arr, int size)
	{
		int left = 0;
		int right = size - 1;

		while (left <= right) {
			int middle = (left + right) / 2;
			
			if (arr[middle] == element) {
				// Element found
				return middle;
			}
			else if (arr[middle] < element) {
				// Search in the right-half: (middle+1..right)
				left = middle + 1;
			}
			else if (arr[middle] > element) {
				// Search in the left-half: (left..middle-1)
				right = middle - 1;
			}
		}

		return kNotFound; // ELement not found
	}

	void Print(const vector<int>& v)
	{
		cout << "[ ";
		for (int x : v) {
			cout << x << ' ';
		}
		cout << ']' << endl;
	}
	
	void TestSearch(const vector<int>& v, function<int(int, const int*, int)>&& search)
	{
		Print(v);

		cout << "Element to search? ";
		int x;
		cin >> x;

		cout << endl;

		int pos = search(x, v.data(), v.size());
		if (pos == kNotFound) {
			cout << "Element not found." << endl;
		}
		else {
			cout << "Element found at index " << pos << '.' << endl;
		}
	}

	void TestLinearSearch()
	{
		vector<int> v{ 33, 44, 55, 11, 22 };
		TestSearch(v, LinearSearch);
	}

	void TestBinarySearch()
	{
		vector<int> v{ 11, 22, 33, 44, 55 };
		TestSearch(v, BinarySearch);
	}

}

namespace Module4
{
	void StackDemo()
	{
		Stack<int> stack{ 10 };
		assert(stack.IsEmpty());
		assert(stack.MaxSize() == 10);

		cout << "Stack created: " << endl;
		cout << stack;

		cout << "Pushing elements:" << endl;
		cout << "stack.Push(10)" << endl;
		cout << "stack.Push(20)" << endl;
		cout << "stack.Push(64)" << endl;
		stack.Push(10);
		stack.Push(20);
		stack.Push(64);
		assert(stack.Size() == 3);
		cout << stack;

		cout << "stack.Pop(): " << stack.Pop() << endl;
		cout << "stack.Pop(): " << stack.Pop() << endl;
		assert(stack.Size() == 1);
		assert(!stack.IsEmpty());

		cout << "stack.Top(): " << stack.Top() << endl;
		assert(stack.Size() == 1);

		cout << "Current stack: " << endl;
		cout << stack;
	}

	void StackOverflowTestDemo()
	{
		// Guard stack push against overflow
		try {
			Stack<int> stack{ 5 };
			cout << "Created stack of max size: " << stack.MaxSize() << endl;

			// Keep pushing until the stack overflows...
			while (true) {
				cout << "Trying: stack.Push(64); ...";
				stack.Push(64);
				cout << "OK." << endl;
			}
		}
		catch (const StackOverflowException&) {
			cout << endl << "*** Stack Overflow detected ***" << endl << endl;
		}
	}
}

namespace Module5
{
	void LinkedListDemo()
	{
		List<int> l{};
		cout << "Created an empty list: " << l << endl << endl;

		cout << "Inserting some elements..." << endl;
		l.InsertHead(10);
		l.InsertHead(64);
		l.InsertHead(80);
		l.InsertHead(77);
		cout << "Current list: " << l << endl << endl;

		cout << "Inserting a new element (500) after node with value 64." << endl;
		auto pos = l.Find(64);
		l.InsertAfter(pos, 500);
		cout << "Current list: " << l << endl << endl;

		cout << "Removing current head." << endl;
		l.RemoveHead();
		cout << "Current list: " << l << endl << endl;

		cout << "Clearing the whole list." << endl;
		l.Clear();
		cout << "Current list: " << l << endl << endl;
	}
}

int main()
{
	//Module1::FirstSample();
	//Module1::AccessingElements();
	//Module1::BoundsChecking();
	//Module2::ConvinientlyPrintArrays();
	//Module2::SubtleBugWhenCopyingArray();
	//Module3::TestLinearSearch();
	//Module3::TestBinarySearch();
	//Module4::StackDemo();
	//Module4::StackOverflowTestDemo();
	Module5::LinkedListDemo();
	system("pause");
}
