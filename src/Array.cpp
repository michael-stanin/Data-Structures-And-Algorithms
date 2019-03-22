#include "Array.hpp"


IntArray::IntArray() = default;
IntArray::IntArray(int size)
{
    if (size != 0) {
        m_ptr = new int[size]{};
        m_size = size;
    }
}

IntArray::~IntArray()
{
	delete[] m_ptr;
}

int& IntArray::operator[](int index)
{
	if (!IsValidIndex(index)) {
		throw IndexOutOfBoundsException{};
	}
	return m_ptr[index];
}

int IntArray::operator[](int index) const
{
	if (!IsValidIndex(index)) {
		throw IndexOutOfBoundsException{};
	}
	return m_ptr[index];
}

bool IntArray::IsValidIndex(int index) const
{
	return (index >= 0) && (index < m_size);
}

std::ostream& operator<<(std::ostream& os, const IntArray& arr)
{
    os << '[ ';
    for (int i = 0; i < arr.Size(); i++) {
        os << arr[i] << ' ';
    }
    os << ']' ;

    return os;
}