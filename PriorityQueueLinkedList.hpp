#pragma once
#include "PriorityQueue.hpp"

template<typename T, typename U = unsigned>
class PriorityQueueLinkedList: public PriorityQueue<T,U>{
private:
	Node<T,U>* head = nullptr;

	Node<T,U>* getNodePtrAtIndex(unsigned index) {
		if (isEmpty() || index >= size)
			throw std::out_of_range("Out of range in linked list in .getNodePtrAtIndex()");


		Node<T,U>* tempNodePtr = head;
		for (int i = 0; i < index; i++)
			tempNodePtr = tempNodePtr->nextNode;

		return tempNodePtr;
	}
public:
	using PriorityQueue<T,U>::size;
	using PriorityQueue<T, U>::isEmpty;
	PriorityQueueLinkedList() = default;

	virtual void push(T value, U priority) {

		Node<T, U>* newNodePtr = new Node<T, U>(value, priority);

		if (isEmpty()) {
			head = newNodePtr;
		} else {
			newNodePtr->nextNode = head;
			head = newNodePtr;
			Node<T, U> *currNodePtr = head;

			while (currNodePtr->nextNode) {
				if (currNodePtr->priority >= currNodePtr->nextNode->priority)
					break;
				std::swap(currNodePtr->value, currNodePtr->nextNode->value);
				std::swap(currNodePtr->priority, currNodePtr->nextNode->priority);
				
				currNodePtr = currNodePtr->nextNode;
			}
		}
		++size;
	}
	virtual Node<T, U> pop() {
		if (isEmpty())
			throw std::out_of_range("Out of range in .pop() function");

		Node<T, U>* tempNodePtr = head;
		head = head->nextNode;
		Node<T, U> tempValue = *tempNodePtr;

		--size;
		delete tempNodePtr; 

		return tempValue;
	}

	void show() {
		if (isEmpty()) {
			std::cout << "List is empty!" << std::endl;
			return;
		}

		Node<T,U>* tempNodePtr = head;
		std::cout << "Priority\tValue" << std::endl;
		while (tempNodePtr) {
			std::cout << tempNodePtr->priority << "\t" << tempNodePtr->value << std::endl;
			tempNodePtr = tempNodePtr->nextNode;
		}
	}
};
