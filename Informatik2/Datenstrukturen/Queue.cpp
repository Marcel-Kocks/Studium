#include <stdlib.h>
#include "Queue.h"


template<typename T>
Queue<T>::Queue(int size)
{
	anchor = (T *)calloc(size, sizeof(T));
	if (anchor == nullptr)
		throw "Malloc Error";
	write = read = anchor;
}

template<typename T>
Queue<T>::~Queue()
{
	if (anchor != nullptr)
		free(anchor);
}

template<typename T>
bool Queue<T>::enqueue(const T in)
{

	return false;
}
