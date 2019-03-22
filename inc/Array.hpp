#pragma once
#include <ostream>
#include <utility>

class IndexOutOfBoundsException {};

template <typename T>
class Array
{
private:
    T* m_ptr{nullptr};
    int m_size{0};

	bool IsValidIndex(int index) const;

    friend std::ostream& operator<<(std::ostream& os, const Array& arr);
    friend void swap(Array& arr1, Array& arr2) noexcept // This way the compiler will generate optimised code
                                                              // without properly dealing with exceptions
    {
        using std::swap;

        // Memberwise swap
        swap(arr1.m_ptr, arr2.m_ptr);
        swap(arr1.m_size, arr2.m_size);
    }

public:
    Array();
    explicit Array(int size);
    Array(const Array& source);
    Array& operator=(Array source);

    Array(Array&& source) { //R-Value reference, temporary object - we can safely "steal" the data from it
        // Transfer ownership from source
        m_ptr = source.m_ptr;
        m_size = source.m_size;

        // Clear source
        source.m_ptr = nullptr;
        source.m_size = 0;
    }

    ~Array();

    int Size() const {
        return m_size;
    }

    bool IsEmpty() const {
        return m_size == 0;
    }

	int& operator[](int index);
	int operator[](int index) const;
};
