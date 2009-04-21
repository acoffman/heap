#include <iostream>
#include <string>
#include "Heap.h"

using namespace std;

int main(){
	Heap<int> testHeap;

	testHeap.loadFromFile("entry");

	int x = 0;
	while (x < 100){
		cout << testHeap.removeMin() << endl;
		++x;
	}

	return 0;
}
