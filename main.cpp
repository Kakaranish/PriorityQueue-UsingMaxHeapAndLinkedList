#include <iostream>
#include <cstdio>
#include <conio.h>
#include "PriorityQueueMaxHeap.hpp"
#include "PriorityQueueLinkedList.hpp"

template <typename T, typename U>
bool loadQueueFromFile(std::string filename, PriorityQueue<T, U> *&queue)
{
	std::ifstream file;
	file.open(filename, std::ios::in);
	if (!file.is_open())
		return false;

	std::string token;
	int amountOfData;
	std::getline(file, token);
	amountOfData = std::stoi(token);

	PriorityQueueMaxHeap<T, U> *caster = dynamic_cast<PriorityQueueMaxHeap<T, U> *>(queue);
	if (caster)
		queue = new PriorityQueueMaxHeap<T, U>(amountOfData);
	else
		queue = new PriorityQueueLinkedList<T, U>();

	while (std::getline(file, token))
	{
		std::vector<std::string> partOfLine = split(token, ' ');
		queue->push(partOfLine[0], std::stoi(partOfLine[1]));
	}

	return true;
}

int main(int argc, char *argv[])
{

	PriorityQueue<std::string, int> *q = new PriorityQueueMaxHeap<std::string, int>();
	if (loadQueueFromFile("Res/test.txt", q))
	{
		q->show();
	}
	for (int i = 0; i < 5; i++)
		std::cout << q->pop().value << std::endl;

	std::cout << std::endl;
	PriorityQueue<std::string, int> *q1 = new PriorityQueueLinkedList<std::string, int>();
	if (loadQueueFromFile("test.txt", q1))
	{
		q1->show();
	}
	for (int i = 0; i < 5; i++)
		std::cout << q1->pop().value << std::endl;

	_getch();
	return 0;
}
