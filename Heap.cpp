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


