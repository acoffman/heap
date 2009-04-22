#include <iostream>
#include <string>
#include "Heap.h"

using namespace std;

int main(){
	Heap<int> testHeap;

	int num = testHeap.loadFromFile("entry");

	while (!testHeap.isEmpty()){
		cout << testHeap.removeMin() << endl;
	}

	cout << endl << num;

	return 0;
}
