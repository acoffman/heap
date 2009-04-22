/******************************
 * Author: Adam Coffman
 *
 * Filename: Heap.h
 *
 * Description: This is the header file the Heap class.
 * 	 Like the book, I have used the array-based implementation.
 * 	 The percolate up and down algorithms are very closesly based
 * 	 on the ones in the textbook.
 *
 * ******************************/
#ifndef HEAP_H

#define HEAP_H

#include <vector>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
class Heap{
	public: 
		//Constructor
		Heap();
		//Inserts a value in the correct location in the heap
		void insertValue(T value);
		//Removes the minimun value from the heap and returns it
		T removeMin();
		//Emptys the heap
		void empty();
		//Loads whitespace delimited values from a file
		//returning how many were loaded.
		int loadFromFile(string fileName);
		//Returns true if the heap is empty.
		bool isEmpty();	

	private:
		//Data structure used to store the heap
		vector<T> heap;
		//Number of elements in the heap
		int size;
		//Used for removeMin, percolates values down the heap.
		void percolateDown(int hole);
};

#include "Heap.cpp"

#endif