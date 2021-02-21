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
#include <vector>

using namespace std;

template <typename T>
class BinaryTree
{
private:

    T *pData;

    BinaryTree<T> *leftNode;
    BinaryTree<T> *rightNode;

public:

    // Constructor TODO 1.1
    BinaryTree() {
	srand(time(NULL));
	pData = nullptr;
	leftNode = nullptr;
	rightNode = nullptr;
    }

    // Destructor TODO 1.1
    // Free up data for pData, left and right node
    ~BinaryTree() {
	void clear(BinaryTree<T> *root){
		if(root != NULL){
			if(!(root -> left) && !(root -> right)){
				delete data;
			}
			if(root -> left) clear(root -> left);
			if(root -> right) clear(root -> right);
			delete root -> left;
			delete root -> right;
			delete data;
		}
	}
    }

    // Inspect if the current node has data. TODO 1.2
    bool hasData() {
        return pData != NULL;
    }

    // Set data for current node. TODO 1.2
    void setData(T data) {
	if (pData == NULL)
		pData = new T;
	*pData = data;
    }

    // Get current node's data. TODO 1.2
    T getData() {
	T val;
	if (pData != NULL)
		val = *pData;
	return val;
    }

    // Set left subtree. TODO 1.2
    void setLeftSubtree(BinaryTree<T> *node) {
	if (leftNode != NULL)
			delete leftNode;

		leftNode = node;
    }

    // Get the left subtree. TODO 1.2
    BinaryTree<T> *getLeftSubtree() {
        return leftNode;
    }

    // Set right subtree. TODO 1.2
    void setRightSubtree(BinaryTree<T> *node) {
	if (rightNode != NULL)
		delete rightNode;
	rightNode = node;
    }

    // Get the right subtree. TODO 1.2
    BinaryTree<T> *getRightSubtree() {
        return rightNode;
    }

    // Insert data recursively randomly where it is possible. TODO 1.3
    // compute a random value: 0 or 1.
    // http://www.cplusplus.com/reference/cstdlib/rand/
    // if 0 insert in left subtree like so:
    //   - if left subtree has data, then call insert recursively on it
    //   - else insert data into left node
    // else insert in right following exact same logic
    void insertRandomRecursively(T data) {
	if (rand() % 2) {
		if (leftNode != NULL)
			leftNode->insertRandomRecursively(data);
		else
			insertLeft(data);
	} 
	else 
	{
		if (rightNode != NULL)
			rightNode->insertRandomRecursively(data);
		else
			insertRight(data);
	}
    }

    // Insert data into left subtree. TODO 1.3
    // If left node doesn't exist then allocate memory for it.
    // After that, set data on it.
    void insertLeft(T data) {
	setLeftSubtree(new BinaryTree<T>());
	leftNode->setData(data);
    }

    // Insert data into right subtree. TODO 1.3
    // If right node doesn't exist then allocate memory for it.
    // After that, set data on it.
    void insertRight(T data) {
	setRightSubtree(new BinaryTree<T>());
	rightNode->setData(data);
    }

    // Display the binary tree to output. TODO 2.1
    void displayTree(int indentLevel) {
		if (leftNode != NULL)
			leftNode->displayTree(indentLevel + 1);
		if (pData != NULL)
			cout<<*pData << " ";
		if (rightNode != NULL)
			rightNode->displayTree(indentLevel + 1);
		if (indentLevel == 0)
			cout<<endl;
    }

    // Return the height of the binary tree. TODO 2.2
    int getTreeHeight() {
        	int leftTreeHeight, rightTreeHeight;
		leftTreeHeight = (leftNode == NULL) ?
				 0 : leftNode->getTreeHeight();
		rightTreeHeight = (rightNode == NULL) ?
				  0 : rightNode->getTreeHeight();

		return 1 + ((leftTreeHeight > rightTreeHeight) ?
			     leftTreeHeight : rightTreeHeight);
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
    /*vector<T> getLevel(int level) {
        std::vector<T> ans;
	void showlevel(BinaryTree<T> *root){
		while(root -> leftNode){
			root = root -> leftNode;
			if(root -> leftNode) showlevel(root -> leftNode);
			if(root -> rightNode) showlevel(root -> rightNode);
			cout << root -> leftNode << " ";
			cout << root -> rightNode << " ";
		}
	}
    }*/
};


#endif // __BINARY_TREE_H
