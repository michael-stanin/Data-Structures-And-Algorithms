#pragma once

class IntArray
{
private:
    int* m_ptr{nullptr};
    int m_size{0};

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
};
