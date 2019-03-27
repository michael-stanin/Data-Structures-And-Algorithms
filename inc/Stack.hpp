#pragma once

#include "Array.hpp"
#include <ostream>

// Represents a stack overflow error.
// Can be derived from std::runtime_error
class StackOverflowException {};

// Represents a stack underflow error.
// Can be derived from std::runtime_error
class StackUnderflowException {};

template <typename T>
class Stack
{
private:
	Array<T> m_array; // Stack elements are stored in this array
	int      m_top;   // Index of the top element (-1 for empty stack)

public:

	explicit Stack(int maxStackSize)
		: m_array{ maxStackSize }
		, m_top{ -1 }				// Empty stack
	{}

	void Push(const T& element) {
		// Before pushing on top of the stack, check that there's enough room
		if (Size() >= MaxSize()) {
			// There's not enough room in this stack for pushing a new element
			throw StackOverflowException{};
		}

		// Push element on top of the stack
		m_array[++m_top] = element;
	}

	T Pop() {
		// Before popping the top of the stack, check that there is a top
		if (IsEmpty()) {
			// There are no more elemnts in the stack
			throw StackUnderflowException{};
		}

		T topElement = m_array[m_top--];
		return topElement;
	}

	T& Top() {
		return m_array[m_top];
	}

	const T& Top() const {
		return m_array[m_top];
	}

	int Size() const {
		return (m_top + 1);
	}

	bool IsEmpty() const {
		return Size() == 0;
	}

	int MaxSize() const {
		return m_array.Size();
	}

	void Clear() {
		// NOTE: This is simply resetting the top index
		m_top = -1;
	}

	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
		if (stack.IsEmpty()) {
			os << "[*** Empty Stack ***]" << std::endl << std::endl;
		}

		os << "[Stack]" << std::endl;
		// Print stack content from top to bottom
		for (int i = stack.m_top; i >= 0; i--) {
			os << "  " << stack.m_array[i] << std::endl;
		}
		os << std::endl;

		return os;
	}
};