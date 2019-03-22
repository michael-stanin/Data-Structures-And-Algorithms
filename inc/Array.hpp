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

	bool IsValidIndex(int index) const {
		return (index >= 0) && (index < m_size);
	}

	void HandleInvalidIndex(int index) const  {
		if (!IsValidIndex(index)) {
			throw IndexOutOfBoundsException{};
		}
	}

	// Swap two array objects (member-wise swap)
	friend void swap(Array& arr1, Array& arr2) noexcept // This way the compiler will generate optimised code
	                                                          // without properly dealing with exceptions
	{
		using std::swap;
		
		// Memberwise swap
		swap(arr1.m_ptr, arr2.m_ptr);
		swap(arr1.m_size, arr2.m_size);
	}

public:

	// Default constructor
	Array() = default;

	// Constructor to create an array with the given size (element count)
	explicit Array(int size) {
		if (size != 0) {
			m_ptr = new T[size]{};
			m_size = size;
		}
	}

	// Copy constructor
	Array(const Array& source) {
		if (!source.IsEmpty()) {
			m_size = source.m_size;

			m_ptr = new T[m_size]{};

			for (int i = 0; i < m_size; i++) {
				m_ptr[i] = source.m_ptr[i];
			}
		}
	}
	
	// Assignment operator (via copy-and-swap idiom)
	Array& operator=(Array source) {// Pass by value so this will create the copy
		swap(*this, source); // Memberwise swap
		return *this;
	} // Calls the destructor of the copy

	// Move constructor
	Array(Array&& source) { //R-Value reference, temporary object - we can safely "steal" the data from it
		// Transfer ownership from source
		m_ptr = source.m_ptr;
		m_size = source.m_size;
		
		// Clear source
		source.m_ptr = nullptr;
		source.m_size = 0;
	}

	// Destructor
	~Array() {
		delete[] m_ptr;
	}

	int Size() const {
		return m_size;
	}

	bool IsEmpty() const {
		return m_size == 0;
	}

	// Safe element access with bounds checking
	T& operator[](int index) {
		HandleInvalidIndex(index);
		return m_ptr[index];
	}

	// Safe read-only element access with bounds checking
	T operator[](int index) const {
		HandleInvalidIndex(index);
		return m_ptr[index];
	}
};

// Enable idiomatic stream insertion for Array objects
// (e.g. cout << ... << myArray << ...)
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
	os << "[ ";
	for (int i = 0; i < arr.Size(); i++) {
		os << arr[i] << ' ';
	}
	os << ']';

	return os;
}
