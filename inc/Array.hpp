#pragma once
#include <iostream>

class IndexOutOfBoundsException {};

class IntArray
{
private:
    int* m_ptr{nullptr};
    int m_size{0};

	bool IsValidIndex(int index) const;

    friend std::ostream& operator<<(std::ostream& os, const IntArray& arr);
    friend void swap(IntArray& arr1, IntArray& arr2) noexcept // This way the compiler will generate optimised code
                                                              // without properly dealing with exceptions
    {
        using std::swap;

        // Memberwise swap
        swap(arr1.m_ptr, arr2.m_ptr);
        swap(arr1.m_size, arr2.m_size);
    }

public:
    IntArray();
    explicit IntArray(int size);
    IntArray(const IntArray& source);
    IntArray& operator=(IntArray source);

    IntArray(IntArray&& source) { //R-Value reference, temporary object - we can safely "steal" the data from it
        // Transfer ownership from source
        m_ptr = source.m_ptr;
        m_size = source.m_size;

        // Clear source
        source.m_ptr = nullptr;
        source.m_size = 0;
    }

    ~IntArray();

    int Size() const {
        return m_size;
    }

    bool IsEmpty() const {
        return m_size == 0;
    }

	int& operator[](int index);
	int operator[](int index) const;
};
