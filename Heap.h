#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
class Heap{
	
	public: 
		Heap();
		void insertValue(T value);
		T removeMin();
		void empty();
		int loadFromFile(string fileName);

	private:
		vector<T> heap;
		int size;
		void percolateDown(int hole);
};

#include "Heap.cpp"

#endif