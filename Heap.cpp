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
		while(!fin.eof()){
			T entry;
			fin >> enter;
			insertValue(entry);
			++count;
		}
	}
	return count;
}

template <class T>
void Heap<T>::insertValue(T val){
	if(size == heap.size()-1)
		heap.resize(heap.size() * 2);

	int hole = ++size;

	//this is where the percolate up happens
	for(;hole > 1 && val < heap[hole/2]; hole /=2)
		array[hole] = array[hole/2];

	array[hole] = x;
}

template <class T>
T Heap<T>::removeMin(){
	if(heap.empty()){
		cerr << "HEAP IS EMPTY!";
		exit(1);
	}
		

	T removed = array[1];
	array[1] = array[size--];
	percolateDown(1);

	return removed;
}

template <class T>
void Heap<T>::percolateDown(int hole){
	
	int childNode;
	T tmp = heap[hole];

	for(;hole*2 <= size; hole = child){
		child = hole*2;
		if(child != size && array[child +1] < array[child])
			child++;
		if(array[child] < tmp)
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = tmp;
}
