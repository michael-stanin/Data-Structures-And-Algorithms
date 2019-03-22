#include "Array.hpp"
#include <cassert>

template<typename T>
Array::Array() = default;

template<typename T>
Array::Array(int size)
{
    if (size != 0) {
        m_ptr = new T[size]{};
        m_size = size;
    }
}

template<typename T>
Array::Array(const Array& source)
{
    if (!source.IsEmpty()) {
        m_size = source.m_size;

        m_ptr = new T[m_size]{};

        for (int i = 0; i < m_size; i++) {
            m_ptr[i] = source.m_ptr[i];
        }
    }
}

template<typename T>
Array& operator=(Array source) // Pass by value so this will create the copy
{
    swap(*this, source); // Memberwise swap
    return *this;
} // Calls the destructor of the copy

template<typename T>
Array::~Array()
{
	delete[] m_ptr;
}

template<typename T>
int& Array::operator[](int index)
{
	if (!IsValidIndex(index)) {
		throw IndexOutOfBoundsException{};
	}
	return m_ptr[index];
}

template<typename T>
int Array::operator[](int index) const
{
	if (!IsValidIndex(index)) {
		throw IndexOutOfBoundsException{};
	}
	return m_ptr[index];
}

template<typename T>
bool Array::IsValidIndex(int index) const
{
	return (index >= 0) && (index < m_size);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array& arr)
{
    os << '[ ';
    for (int i = 0; i < arr.Size(); i++) {
        os << arr[i] << ' ';
    }
    os << ']' ;

    return os;
}
