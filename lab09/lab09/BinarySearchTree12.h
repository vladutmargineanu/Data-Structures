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
private:
    BinarySearchTree<T> *leftNode;
    BinarySearchTree<T> *rightNode;
    BinarySearchTree<T> *parent;
    T *pData;
public:

    BinarySearchTree() {
        // TODO 1.1
      pData = NULL;
      leftNode = rightNode = NULL;

    }
    ~BinarySearchTree() {
        // TODO 1.2
      if(pData != NULL)
        delete pData;

    }
    
    bool isEmpty() {
        return (pData == nullptr);
    }
 
    void insertKey(T x) {
        // TODO 1.3
      if(pData == NULL){
        pData = new T;
        *pData = x;
      }
      if(*pData < x) {
        if(rightNode == NULL) {
          rightNode = new BinarySearchTree<T>;
          rightNode->parent = this;
        }
        rightNode->insertKey(x);
      }
      if(*pData > x){
        if(leftNode == NULL) {
          leftNode = new BinarySearchTree<T>;
          leftNode->parent = this;
        }
        leftNode->insertKey(x);
      }

    }
    
    BinarySearchTree<T>* searchKey(T x) {
        if(pData == NULL)
          return this;
        if(*pData < x){
          if(rightNode){
            return rightNode->searchKey(x);
          }
        }
        if(*pData > x){
          if(leftNode){
            return leftNode->searchKey(x);
          }
        }
        if(*pData == x)
          return this;
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
 
};
 
#endif // __BINARY_SEARCH_TREE_H

