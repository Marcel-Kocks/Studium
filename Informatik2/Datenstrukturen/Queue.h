#pragma once

template <typename T>
class Queue
{
public:
	Queue(int size);
	~Queue();

	bool enqueue(const T in);
	const T dequeue();
	const T peek();


private:
	T * anchor;
	T * read;
	T * write;
};


