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
#include "math.h"
#include <vector>
#include <iostream>

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
	void cascadingCut(FibNode<T>* node);
	FibNode<T>* remove(FibNode<T>* node);
	FibNode<T>* getMin();
	int getSize();
	void deleteMin(FibNode<T> *result);
	void consolidate();
	int maxRank();
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
	if(node->parent != 0L){
		node->left->right = node->left;
		node->right->left = node->right;

		node->parent->rank--;
		node->parent = 0L;
		size++;
		mergeLists(min, node);
		node->mark = false;
	}
}

template <class T>
void FHeap<T>::cascadingCut(FibNode<T>* node){
	if(node->parent){
		if(node->mark){
			cut(node);
			cascadingCut(node->parent);
		} else {
			node->mark = true;
		}
	}
}

template <class T>
FibNode<T>* FHeap<T>::remove(FibNode<T>* node){
	/*if(node->parent != 0L){
		//add check for onlychild
		if(node->parent->rank == 1){
			//remove parents child, when only child
			node->parent->child = 0L;
		}
		else{
			//check if node to delete is pointer in child list of parent
			if(node->parent->child == node){
				node->parent->child = node->left;
			}
		}
		node->parent->rank--;
	}
	else{
		size--;
	}*/
	size--;
	FibNode<T>* n = node->child;
	for(int i = 0; i<node->rank; i++){
		n->parent = 0L;
		FibNode<T>* temp = n;
		n = n->left;
		mergeLists(min, temp);
		size++;
	}
	node->left->right = node->right;
	node->right->left = node->left;
	if(node == min){
		min = node->left;
	}
	return node;
}

template <class T>
FibNode<T>* FHeap<T>::mergeLists(FibNode<T>* a, FibNode<T>* b){
	if(a == 0L && b == 0L){
		return 0L;
	}
	if(a == 0L){
		b->left = b;
		b->right = b;
		return b;
	}
	if(b == 0L){
		a->left = a;
		a->right = a;
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

	child->left->right = child->right;
	child->right->left = child->left;

	child->parent = parent;
	parent->rank++;
	size--;
	child->mark = false;
	parent->child = mergeLists(parent->child, child);
	return parent;
}
template <class T>
int FHeap<T>::maxRank(){
	return 2*log(size);
}

template <class T>
void FHeap<T>::consolidate(){
	int rankSize = maxRank()+1;
	std::vector<FibNode<T>*> rankVec(rankSize);
	//rankVec.reserve(maxRank()+1);

	int initial_size = size;

	FibNode<T>* node = min;
	FibNode<T>* last;
	int counter = 0;
	do{
		std::cout << "Node " << node->key << std::endl;
		last = node;
		while(rankVec[node->rank] ){//&& rankVec[node->rank] != node){
			std::cout << "Key " << rankVec[node->rank]->key << "Rank " << node->rank << std::endl;
			FibNode<T>* node2 = rankVec[node->rank];
			node = link(node, node2);
			rankVec[node->rank-1] = 0L;
			if(node->key < min->key){
				min = node;
			}
		}
		rankVec[node->rank] = node;
		node = node->left;
		std::cout << "Counter " << counter << "Size " << initial_size << std::endl;
		counter++;
	}while(counter < initial_size);
}

template <class T>
void FHeap<T>::deleteMin(FibNode<T> *result){
	if(min){
		FibNode<T>*backup = this->remove(min);
		this->consolidate();

		FibNode<T>* node = min;
		for(int i = 0; i < size; i++){
			node = node->left;
			if(node->key < min->key){
				min = node;
			}
		}
		result->key = backup->key;
		result->content = backup->content;
		delete backup;
		return;
	}
	else{
		return;
	}
}

#endif /* FIBONACCIHEAP_H_ */
