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
	return m_ptr[index];
}

int IntArray::operator[](int index) const
{
	return m_ptr[index];
}
