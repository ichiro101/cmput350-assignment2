#pragma once

template <typename T> 
class Stack 
{
public:

	Stack() {
		allocatedLength = 4;
		logicalLength = 0;
		p = new T[allocatedLength];
	}

	~Stack() {
		delete[] p;
	}

	Stack(const Stack& s) {
		allocatedLength = s.size();
		logicalLength = s.size();

		p = new T[allocatedLength];
		for(int i = 0; i < logicalLength; i++) {
			p[i] = s.p[i];
		}
	}

	Stack &operator=(const Stack &) {
		allocatedLength = s.size();
		logicalLength = s.size();

		p = new T[allocatedLength];
		for(int i = 0; i < logicalLength; i++) {
			p[i] = s.p[i];
		}
	}

	// append an element at the end of the array
	void push(const T& elem) {
		if(allocatedLength == logicalLength) {
			doubleCapacity();
		}

		p[logicalLength] = elem;
		logicalLength++;
	}
	
	// remove last element (precond: !empty)
	void pop() {
		logicalLength--;
	}

	// true iff no element present
	bool empty() const {
		if(logicalLength == 0) {
			return true;
		} else {
			return false;
		}
	}
	
	// return current number of elements
	int size() const {
		return logicalLength;
	}

	// return reference to last element (precond: !empty)
	T &top(){
		if(!empty()) {
			return p[logicalLength - 1];
		}
	}

	// return const ref. ....  
	const T &top() const {
		return top();
	}

private:
	T *p;                       // pointer to array of length capacity
	int allocatedLength;        // current maximum number of elements
	int logicalLength;          // actual number of elements (<= capacity)

	void doubleCapacity() {
		allocatedLength *= 2;
		T* newPointer = new T[allocatedLength];

		for(int i = 0; i < logicalLength; i++) {
			newPointer[i] = p[i];
		}

		delete[] p;
		p = newPointer;
	}
};
