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

public:
    IntArray();
    explicit IntArray(int size);
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
