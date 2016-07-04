/*
 * FibonacciHeap.h
 *
 *  Created on: 03.07.2016
 *      Author: rkorb
 */
//

#ifndef FIBONACCIHEAP_H_
#define FIBONACCIHEAP_H_

#include "FibNode.h"

template <class T>
class FHeap{
private:
	FibNode<T> *min;
	int size;
public:
	FHeap():min(0L), size(0){}
	FibNode<T>* insert(int key, T content);
	static FibNode<T>* mergeLists(FibNode<T>* a, FibNode<T>* b);
	FibNode<T>* link(FibNode<T>* a, FibNode<T>* b);
	void cut(FibNode<T>* node);
	FibNode<T>* getMin();
	int getSize();
	void print();
};

template <class T>
FibNode<T>* FHeap<T>::getMin(){
	return min;
}

template <class T>
int FHeap<T>::getSize(){
	return size;
}

template <class T>
void FHeap<T>::print(){
	FibNode<T> *node = min;
	for(int i = 0; i < size; i++){
		std::cout << node->key << std::endl;
		node = node->right;
	}
}

template <class T>
FibNode<T>* FHeap<T>::insert(int key, T content){
	FibNode<T>* node = new FibNode<T>(key, content);
	min = mergeLists(min, node);
	size++;
	return node;
}

template <class T>
void FHeap<T>::cut(FibNode<T>* node){

}

template <class T>
FibNode<T>* FHeap<T>::mergeLists(FibNode<T>* a, FibNode<T>* b){
	if(a == 0L && b == 0L){
		return 0L;
	}
	if(a == 0L){
		return b;
	}
	if(b == 0L){
		return a;
	}

	b->left = a;
	b->right = a->right;
	b->right->left = b;
	a->right = b;

	if(b->key < a->key){
		return b;
	}
	else{
		return a;
	}
}

template <class T>
FibNode<T>* FHeap<T>::link(FibNode<T>* a, FibNode<T>* b){
	if(a->rank != b->rank){
		return 0L;
	}
	FibNode<T> *parent, *child;
	if(a->key < b->key){
		parent = a;
		child = b;
	}
	else{
		parent = b;
		child = a;
	}
	child->parent = parent;
	parent->rank++;
	size--;
	parent->child = mergeLists(parent->child, child);
	return parent;
}
#endif /* FIBONACCIHEAP_H_ */
