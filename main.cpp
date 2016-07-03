/*
 * main.cpp

 *
 *  Created on: 03.07.2016
 *      Author: rkorb
 */
#include "iostream"
#include "FHeap.h"

int main(){
	FHeap<int> fh;
	fh.insert(10, 10);
	fh.insert(2, 20);
	fh.insert(3, 20);
	fh.print();

	FHeap<int> fh2;
	fh2.insert(5, 10);
	fh2.insert(4, 20);
	fh2.insert(6, 20);
	fh2.print();

	FHeap<int>::link(fh.getMin(), fh2.getMin());
	fh.print();
	return 0;
}



