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

	fh.insert(1, 5);
	fh.insert(1, 6);
	fh.insert(1, 7);
	fh.insert(1, 10);
	fh.insert(1, 12);
	fh.insert(1, 15);
	fh.insert(1, 16);
	fh.insert(1, 17);

	FibNode<int> node;
	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << " Content " << node.getContent() << std::endl;

	fh.insert(2, 0);
	fh.insert(2, 1);

	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << " Content " << node.getContent() << std::endl;

	fh.insert(2, 2);

	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << " Content " << node.getContent() << std::endl;

	fh.insert(2, 20);
	fh.insert(2, 21);

	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << " Content " << node.getContent() << std::endl;

	fh.insert(2, 22);
	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << " Content " << node.getContent() << std::endl;
	/*for(int i = 0; i < 240*240; i++){
		fh.insert(i, i);
	}

	fh.print();

	FibNode<int> node;
	for(int i = 0; i < 240*240; i++){
		if(i == 3){
			std::cout << "Stop"<< std::endl;
		}
		//if(!fh.isEmpty()){
			fh.deleteMin(&node);
			std::cout << "Min " << node.getKey() << " Content " << node.getContent() << std::endl;
		//}
	}*/


	/*FibNode<int> node;
	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << std::endl;
	fh.print();

	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << std::endl;
	fh.print();
	fh.deleteMin(&node);
	std::cout << "Min " << node.getKey() << std::endl;
	fh.print();*/

	return 0;
}



