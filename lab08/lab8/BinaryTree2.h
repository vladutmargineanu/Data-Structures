/**
  * Autor: Victor Carbune
  * Echipa SD, 2012
  *
  * Modificari: Adrian Bogatu
  * Echipa SD, 2013
  *
  * Modificari: Cosmin Petrisor
  * Echipa SD, 2015
  *
  * License: LGPL
  */

#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class BinaryTree
{
private:

	T *pData;

	BinaryTree<T> *leftNode;
	BinaryTree<T> *rightNode;

public:

	// Constructor
	BinaryTree() {
		srand(time(NULL));

		pData = NULL;
		leftNode = rightNode = NULL;
	}

	// Destructor
	~BinaryTree() {
		if (pData != NULL)
			delete pData;

		if (leftNode != NULL)
			delete leftNode;

		if (rightNode != NULL)
			delete rightNode;
	}

	// Inspect if the current node has data
	bool hasData() {
		return (pData != NULL);
	}

	// Set data for current node
	void setData(T data) {
		if (pData == NULL)
			pData = new T;

		*pData = data;
	}

	// Get current node's data
	T getData() {
		T val;

		if (pData != NULL)
			val = *pData;

		return val;
	}

	// Set left subtree
	void setLeftSubtree(BinaryTree<T> *node) {
		if (leftNode != NULL)
			delete leftNode;
		leftNode = new BinaryTree<T>;

		leftNode = node;
	}

	// Get the left subtree
	BinaryTree<T> *getLeftSubtree() {
		return leftNode;
	}

	// Set right subtree
	void setRightSubtree(BinaryTree<T> *node) {
		if (rightNode != NULL)
			delete rightNode;
		rightNode = new BinaryTree<T>;

		rightNode = node;
	}

	// Get the right subtree
	BinaryTree<T> *getRightSubtree() {
		return rightNode;
	}

	// Insert data recursively, randomly, where it is possible
	void insert(T data) {
		if (rand() % 2) {
			if (leftNode != NULL)
				leftNode->insert(data);
			else
				insertLeft(data);
		} else {
			if (rightNode != NULL)
				rightNode->insert(data);
			else
				insertRight(data);
		}
	}

	// Insert data into left subtree
	void insertLeft(T data) {
		setLeftSubtree(new BinaryTree<T>());
		leftNode->setData(data);
	}

	// Insert data into right subtree
	void insertRight(T data) {
		setRightSubtree(new BinaryTree<T>());
		rightNode->setData(data);
	}

	// Display the binary tree to output
	void displayTree(int indentLevel) {
		if (leftNode != NULL)
			leftNode->displayTree(indentLevel + 1);

		if (pData != NULL)
			cout<<*pData;
		cout<<" ";

		if (rightNode != NULL)
			rightNode->displayTree(indentLevel + 1);

		if (indentLevel == 0)
			cout<<endl;
	}

	// Return the height of the binary tree
	int getTreeHeight() {
		int leftTreeHeight, rightTreeHeight;

		leftTreeHeight = (leftNode == NULL) ?
				 0 : leftNode->getTreeHeight();
		rightTreeHeight = (rightNode == NULL) ?
				  0 : rightNode->getTreeHeight();

		return 1 + ((leftTreeHeight > rightTreeHeight) ?
			     leftTreeHeight : rightTreeHeight);
	}

	// Return the number of nodes in the tree
	int getNumNodes() {
		int nodes = 1;

		nodes += (leftNode == NULL) ? 0 : leftNode->getNumNodes();
		nodes += (rightNode == NULL) ? 0 : rightNode->getNumNodes();

		return nodes;
	}
};

#endif	// __BINARY_TREE_H
