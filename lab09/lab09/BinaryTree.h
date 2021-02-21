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
    * Modificari: Cristian Creteanu
    * Echipa SD, 2017
    * 
    * Modificari: Ioana Stefan
    * Echipa SD, 2018
    * License: LGPL
    */

#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <iostream>
#include <cstdlib>
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
    BinaryTree() {
        pData = nullptr;
        leftNode = nullptr;
        rightNode = nullptr;
    }

    ~BinaryTree() {
        if (pData) {
            delete pData;
        }

        if (leftNode) {
            delete leftNode;
        }

        if (rightNode) {
            delete rightNode;
        }
    }

    bool hasData() {
        return pData != nullptr;
    }

    void setData(T data) {
        if (!pData) {
            pData = new T;
        }

        *pData = data;
    }

    T getData() {
        return *pData;
    }

    void setLeftSubtree(BinaryTree<T> *node) {
        if (leftNode) {
            delete leftNode;
        }

        leftNode = node;
    }

    BinaryTree<T> *getLeftSubtree() {
        return leftNode;
    }

    void setRightSubtree(BinaryTree<T> *node) {
        if (rightNode) {
            delete rightNode;
        }

        rightNode = node;
    }

    BinaryTree<T> *getRightSubtree() {
            return rightNode;
    }

    void insertLeft(T data) {
        if (!leftNode) {
            leftNode = new BinaryTree<T>();
        }

        leftNode->setData(data);
    }

    void insertRight(T data) {
        if (!rightNode) {
            rightNode = new BinaryTree<T>();
        }

        rightNode->setData(data);
    }

    /* TODO 5
     *
     * First test on:
                  1
                /   \
               2     3
              / \     \
             4   5     7
            / \
           10  8
        Should return false
     * Second test on:
                  7
               /     \
             3         15
            /  \      /    \
          1     4    9      18
        Should return true
     */
    static bool isBST(BinaryTree* root) {
        /* if (root == NULL) 
    		return false; 
    	if (root->leftNode != NULL && root->leftNode->pData > root->pData) 
    		return true; 
  		 if (root->rightNode != NULL && root->rightNode->pData < root->pData) 
 		return true; 
  		 if (!isBST(root->leftNode) || !isBST(root->rightNode)) 
    		return true;
 	return false;
    */
        // BST = binary search tree (daca este arbore de cautare)
    bool left_ok = true;
    bool right_ok = true;
    
    
    if (root->leftNode){
        if (*(root->leftNode->pData) > *(root->pData))
            return false;
        else
            left_ok = isBST(root->leftNode);
    }  
        
    if (root->rightNode){
        if (*(root->rightNode->pData) < *(root->pData))
            return false;
        else
            right_ok = isBST(root->rightNode);

     }   
    return (left_ok && right_ok);
    
    }

};


#endif // __BINARY_TREE_H
