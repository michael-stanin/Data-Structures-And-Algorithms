#include "Array.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << "Creating an empty array." << endl;
    IntArray a{};
    cout << "a.Size() is " << a.Size() << endl;
    //assert(a.IsEmpty());

    cout << "-------------------------------------------" << endl;

    cout << "Creating an array containing 10 elements" << endl;
    IntArray b{10};
    cout << "b.Size() is " << b.Size() << endl;
    //assert(!b.IsEmpty());
}
