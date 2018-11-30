#pragma once

#include <iostream>
#include <algorithm>

template<typename T>
class GrowArray {
private:
	int used;
	int capacity;
	T* data;
	void checkGrow() {
	    if (capacity == 0) {
	        capacity = 1;
	        data = new T[capacity];
	        return;
	    }
		if (used < capacity)
			return; // don't grow unless you have to
		T* old = data;

		//TODO: every time the list grows, double it!!!
		capacity *= 2;
		data = new T[capacity]; // calls T::T()
		for (int i = 0; i < used; i++)
			data[i] = old[i];

		delete [] old;
	}
public:
	GrowArray() : used(0), capacity(0), data(nullptr) {}
	GrowArray(int initialCapacity) : used(0), capacity(initialCapacity), data(new T[capacity]) {} //TODO: fix! {}

	//TODO: add destructor, copy constructor, operator =
	~GrowArray() {
		delete [] data;
	}

	GrowArray(const GrowArray& orig) {
		used = orig.used;
		capacity = orig.capacity;
		data = new T[capacity];
		for (int i = 0; i < used; ++i) {
			data[i] = orig.data[i];
		}
	}
	// move constructor
	GrowArray(const GrowArray&& orig) noexcept : used(orig.used), capacity(orig.capacity), data(orig.data) {
        orig.data = nullptr;
    }
	GrowArray& operator = (const GrowArray& orig) {
		GrowArray copy(orig);
		used = copy.used;
		capacity = copy.capacity;
		std::swap(data, copy.data);
		return *this;
	}

	void addEnd(const T& v) {
		checkGrow();
		data[used] = v;
        used += 1;
	}

	T removeEnd() {
    	used--;
		return data[used];
	}
	T operator [](int i) const {
		return data[i];
	}

	T& operator [](int i) {
		return data[i];
	}

	friend std::ostream& operator <<(std::ostream& s, const GrowArray<T>& list) {
		for (int i = 0; i < list.used; i++)
			s << list[i] << ' ';
		return s;
	}
};
