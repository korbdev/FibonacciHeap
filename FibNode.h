/*
 * FibNode.h
 *
 *  Created on: 03.07.2016
 *      Author: rkorb
 */

#ifndef FIBNODE_H_
#define FIBNODE_H_

#include "FHeap.h"

template <class T>
class FHeap;

template <class T>
class FibNode{
	friend class FHeap<T>;
private:
	int key;
	T content;
	int rank;
	bool mark;
	FibNode *parent, *child, *left,*right;
public:
	FibNode(int key, T content):key(key),content(content),rank(0),mark(false),parent(0L),child(0L),left(this),right(this){}
};



#endif /* FIBNODE_H_ */
