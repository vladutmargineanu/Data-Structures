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

		pData = nullptr;
		leftNode = rightNode = nullptr;

	}

	// Destructor
	~BinaryTree() {
		if (pData != nullptr)
			delete pData;

		if (leftNode != nullptr)
			delete leftNode;

		if (rightNode != nullptr)
			delete rightNode;
	}

	// Inspect if the current node has data
	bool hasData() {
		return (pData != nullptr);
	}

	// Set data for current node
	void setData(T data) {
		if (pData == nullptr)
			pData = new T;

		*pData = data;
	}

	// Get current node's data
	T getData() {
		T val;

		if (pData != nullptr)
			val = *pData;

		return val;
	}

	// Set left subtree
	void setLeftSubtree(BinaryTree<T> *node) {
		if (leftNode != nullptr)
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
		if (rightNode != nullptr)
            delete rightNode;
        rightNode = new BinaryTree<T>;
		rightNode = node;
	}

	// Get the right subtree
	BinaryTree<T> *getRightSubtree() {
		return rightNode;
	}

	// Insert data recursively, randomly, where it is possible
	void insertRandomRecursively(T data) {
		if (rand() % 2) {
			if (leftNode != nullptr)
				leftNode->insertRandomRecursively(data);
			else
				insertLeft(data);
		} else {
			if (rightNode != nullptr)
				rightNode->insertRandomRecursively(data);
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
		if (leftNode != nullptr)
			leftNode->displayTree(indentLevel + 1);

		if (pData != nullptr)
			cout << *pData;
		cout<<" ";

		if (rightNode != nullptr)
			rightNode->displayTree(indentLevel + 1);

		if (indentLevel == 0)
			cout << endl;
	}

	// Return the height of the binary tree
	int getTreeHeight() {
		int leftTreeHeight, rightTreeHeight;

		leftTreeHeight = (leftNode == nullptr) ?
				 0 : leftNode->getTreeHeight();
		rightTreeHeight = (rightNode == nullptr) ?
				  0 : rightNode->getTreeHeight();

		return 1 + ((leftTreeHeight > rightTreeHeight) ?
			     leftTreeHeight : rightTreeHeight);
	}

	// Return the number of nodes in the tree
	int getNumNodes() {
		int nodes = 1;

		nodes += (leftNode == nullptr) ? 0 : leftNode->getNumNodes();
		nodes += (rightNode == nullptr) ? 0 : rightNode->getNumNodes();

		return nodes;
	}


     // Return the LCA of two nodes in the tree. TODO 2.3
    static BinaryTree<T>* getLCA(BinaryTree<T>* root, BinaryTree<T>* node1, BinaryTree<T>* node2) {
        if(root == NULL) 
        return NULL;
    if(root == node1 || root == node2) 
        return root;
    auto n1 = getLCA(root -> leftNode, node1, node2);
    auto n2 = getLCA(root -> rightNode, node1, node2);
    if(n1 && n2) 
        return root;
    if(n1)
        return n1;
    return n2;
    }

    // Return the top view of the tree. TODO 3.1
    /* Top view explanation: looking at the tree from the top,
     * which nodes will be visible? */
   vector<T> topView() {
        vector<T> topView;
        return topView;
    }

    // Return the bottom view of the tree. TODO 3.1
    /* Bottom view explanation: looking at the tree from the bottom,
     * which nodes will be visible? */
    vector<T> bottomView() {
        vector<T> bottomView;
        return bottomView;
    }

    // Return the side view of the tree. TODO 3.1
    /* Side view explanation: looking at the tree from the left side,
     * which nodes will be visible? */
    vector<T> sideView() {
        vector<T> sideView;
        return sideView;
    }

    /* Given another tree as an argument, return whether or not
    it is identical to the current one. TODO 3.2 */
    bool isIdentical(BinaryTree<T>* that) {
        return false;
    }

    /* Given another tree as an argument, return whether or not
    it is symmetric to the current one. TODO 3.2 */
    bool isSymmetric(BinaryTree* that) {
        return false;
    }

    // Print the level given as parameter. 0 is the level of the root TODO 3.3
    vector<T> getLevel(int level) {
        std::vector<T> ans;
        return ans;
    } 

};

#endif	// __BINARY_TREE_H
