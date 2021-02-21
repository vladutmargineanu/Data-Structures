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

#ifndef __BINARY_SEARCH_TREE__H
#define __BINARY_SEARCH_TREE__H

#include <iostream> 

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() {
        // TODO 1.1
    }
    ~BinarySearchTree() {
        // TODO 1.2
    }
    
    bool isEmpty() {
        return (pData == nullptr);
    }
 
    void insertKey(T x) {
        // TODO 1.3
    }
    
    BinarySearchTree<T>* searchKey(T x) {
        // TODO 1.4
        return nullptr;
    }
    
    std::vector<T> inOrderDisplay() {
        // TODO 1.5
        std::vector<T> res;
        return res;
    }
    
    T findMin() {
        // TODO 2
        return T();
    }
    
    T findMax() {
        // TODO 2
        return T();
    }

    int findLevels() {
        // TODO 3
        return 0;
    }
    
    std::vector<T> displayLevel(int level) {
        // TODO 3
        std::vector<T> res;
        return res;
    }
    
    BinarySearchTree<T>* removeKey(T x) {
        // TODO 4
        return nullptr;
    }
 
private:
    BinarySearchTree<T> *leftNode;
    BinarySearchTree<T> *rightNode;
    BinarySearchTree<T> *parent;
    T *pData;
};
 
#endif // __BINARY_SEARCH_TREE_H

