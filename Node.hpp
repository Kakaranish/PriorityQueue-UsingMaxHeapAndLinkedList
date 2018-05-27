#pragma once

template <typename T, typename U = unsigned>
struct Node
{
  public:
	T value;
	U priority;
	Node<T, U> *nextNode = nullptr;
	Node() = default;
	Node(T _value, U _priority) : value(_value), priority(_priority) {}
};
