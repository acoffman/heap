/******************************
 * Author: Adam Coffman
 *
 * Filename: Heap.c
 *
 * Description: This is the implementation file for
 * 	the Heap class. 
 *
 * ******************************/

//Initialize the heap size to 1 and the number
//of elements to 0
template <class T>
Heap<T>::Heap(){
	size = 0;
	heap.resize(1);
}

//Empty the heap and set the number of elements to zero
template <class T>
void Heap<T>::empty(){
	heap.clear();
	size = 0;
}

//Load in values from a whitespace delimited file
//the int variable count keeps track of how many values
//have been loaded.
template <class T>
int Heap<T>::loadFromFile(string fileName){
	ifstream fin;
	int count = 0;

	fin.open(fileName.c_str());
	if(fin.fail()){
		return -1;
	}else{
		T entry;
		while(fin >> entry){
			insertValue(entry);
			++count;
		}
	}
	fin.close();
	return count;
}

//Insert a value at the bottom-most 
//available spot, and then 
//percolate it up the tree until it reaches
//the correct spot.
template <class T>
void Heap<T>::insertValue(T val){
	//resize the heap array if we need to
	if(size == heap.size()-1)
		heap.resize(heap.size() * 2);

	int hole = ++size;

	//this is where the percolate up happens
	for(;hole > 1 && val < heap[hole/2]; hole /=2)
		heap[hole] = heap[hole/2];

	heap[hole] = val;
}

//Removes the minimum value in the heap, and then performs the percolate
//down operation to maintain heap order.
//Prints a message to cerr and exits if the heap is empty.
//Returns the value that was removed.
template <class T>
T Heap<T>::removeMin(){
	if(size == 0){
		cerr << "HEAP IS EMPTY!" << endl;
		exit(1);
	}
		

	T removed = heap[1];
	heap[1] = heap[size--];
	percolateDown(1);

	return removed;
}

//If there are no elements in the heap,
//return true
template <class T>
bool Heap<T>::isEmpty(){
	return size == 0;
}

//This function percolates a value from the top
//of the "tree" down to its proper location, after the
//minimum value has been removed. 
template <class T>
void Heap<T>::percolateDown(int hole){
	
	int child;
	T tmp = heap[hole];

	for(;hole*2 <= size; hole = child){
		child = hole*2;
		if(child != size && heap[child +1] < heap[child])
			child++;
		if(heap[child] < tmp)
			heap[hole] = heap[child];
		else
			break;
	}
	heap[hole] = tmp;
}
