#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
class Heap{
	
	public: 
		void insertValue(T value);
		T removeMin();
		void empty();
		int loadFromFile(string fileName);

	private:
		vector<T> heap;
		void percolateUp(T val);
		void percolateDown(T val);
};

#include "Heap.cpp"

#endif