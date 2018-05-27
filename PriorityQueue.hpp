#pragma once
#include "Utility.hpp"
#include "Node.hpp"

//T - value type
//U - priority 
template<typename T, typename U = unsigned>
class PriorityQueue {
protected:
	std::size_t size = 0; 
public:
	virtual void push(T value, U priority) = 0;
	virtual Node<T, U> pop() = 0;
	inline std::size_t getSize() const { return size; }
	bool isEmpty() const { return (size > 0) ? false : true; }
	virtual void show() = 0;
};

