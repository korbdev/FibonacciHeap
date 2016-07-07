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
	FibNode<int> *n1, *n2, *n3, *n4, *n5, *n6;
	std::cout << "Insert" << std::endl;
	n1 = fh.insert(1, 10);
	n2 = fh.insert(7, 1);
	n3 = fh.insert(3, 20);
	n4 = fh.insert(7, 2);
	n5 = fh.insert(5, 20);
	n6 = fh.insert(6, 20);
	n6 = fh.insert(60, 20);
	fh.print();

	//fh.consolidate();
	//fh.print();

	FibNode<int> min;
	fh.deleteMin(&min);
	std::cout << "Min " << min.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&min);
	std::cout << "Min "  << min.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&min);
	std::cout << "Min "  << min.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&min);
	std::cout << "Min "  << min.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&min);
	std::cout << "Min "  << min.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&min);
	std::cout << "Min "  << min.getKey() << std::endl;
	fh.print();

	return 0;
}



