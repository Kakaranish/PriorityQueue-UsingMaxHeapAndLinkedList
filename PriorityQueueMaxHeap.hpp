#pragma once
#include "PriorityQueue.hpp"

template <typename T, typename U = unsigned>
class PriorityQueueMaxHeap : public PriorityQueue<T, U>
{
  private:
	//USING
	using PriorityQueue<T, U>::size;
	using PriorityQueue<T, U>::isEmpty;

	//FIELDS
	Node<T, U> *arr;
	std::size_t max_size;
	//METHODS
	void heapify_up()
	{
		std::size_t currParentIndex, currentIndex = PriorityQueue<T, U>::size;

		while ((currParentIndex = (currentIndex - 1) / 2) <= max_size)
		{
			if (arr[currParentIndex].priority < arr[currentIndex].priority)
				std::swap(arr[currParentIndex], arr[currentIndex]);
			else
				break;

			currentIndex = currParentIndex;
		}
	}
	void heapify_down()
	{
		std::size_t currParentIndex, lChildIndex, rChildIndex;
		std::size_t biggerChild_index;

		for (int i = 0;; i++)
		{
			if (!i)
				currParentIndex = 0;

			lChildIndex = 2 * currParentIndex + 1;
			rChildIndex = 2 * currParentIndex + 2;

			if (lChildIndex < size)
			{
				if (rChildIndex < size)
					if (arr[lChildIndex].priority > arr[rChildIndex].priority)
						biggerChild_index = lChildIndex;
					else
						biggerChild_index = rChildIndex;
				else
					biggerChild_index = lChildIndex;
			}
			else
				break;

			if (arr[currParentIndex].priority < arr[biggerChild_index].priority)
				std::swap(arr[currParentIndex], arr[biggerChild_index]);
			else
				break;

			currParentIndex = biggerChild_index;
		}
	}

  public:
	PriorityQueueMaxHeap(unsigned _max_size = 0) : max_size(_max_size)
	{
		if (_max_size)
			arr = new Node<T, U>[max_size];
	}

	virtual void push(T value, U priority)
	{
		if (size >= max_size)
			throw std::out_of_range("Heap overflow! Reached max size!");
		arr[size] = Node<T, U>(value, priority);
		heapify_up();
		++size;
	}
	virtual Node<T, U> pop()
	{
		if (isEmpty())
			throw std::out_of_range("Heap is empty! Out of range in .pop()");

		std::swap(arr[0], arr[--size]);

		heapify_down();
		return arr[size];
	}

	virtual void show()
	{
		if (isEmpty())
		{
			std::cout << "Heap is empty!" << std::endl;
			return;
		}

		std::cout << "Priority\tValue" << std::endl;
		for (int i = 0; i < size; i++)
			std::cout << arr[i].priority << "\t" << arr[i].value << std::endl;
	}
	inline std::size_t getMaxSize() const { return max_size; }
};
