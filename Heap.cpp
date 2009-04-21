template <class T>
Heap<T>::Heap(){
	size = 0;
	heap.resize(1);
}

template <class T>
void Heap<T>::empty(){
	heap.clear();
}

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

template <class T>
void Heap<T>::insertValue(T val){
	if(size == heap.size()-1)
		heap.resize(heap.size() * 2);

	int hole = ++size;

	//this is where the percolate up happens
	for(;hole > 1 && val < heap[hole/2]; hole /=2)
		heap[hole] = heap[hole/2];

	heap[hole] = val;
}

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
