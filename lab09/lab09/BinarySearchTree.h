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
        pData = NULL;
        leftNode = rightNode = NULL;
    }
    ~BinarySearchTree() {
         if (pData != NULL) {
          delete pData;
         }
         if (leftNode) {
           delete leftNode;
        }
        if (rightNode) {
           delete rightNode;
         }
    }
    
    bool isEmpty() {
        return (pData == nullptr);
    }
    
    // functia se apeleaza din main pentru radacina mereu si se ajunge la nodul dorit, recursiv prin cautare binara
    void insertKey(T x) {
    	// se creaza radacina in main (*root care are elementele private: leftNode, rightNode, pData, parent)
    	// elementele leftNode, rightNode si parent sunt de tip BinarySearchTree
    	// constructourul le seteaza la null elementele private
      if(pData == NULL){
      	// arborele este vid si se creeaza in main root
        pData = new T;
        *pData = x;
      }
      // arborele nu este vid si se insereaza cheia in arborele stang sau drept
      if(*pData < x) {
        if(rightNode == NULL) {
          rightNode = new BinarySearchTree<T>;
          // this =(este) *root
          // functia se apeleaza pentru root in main (intodeauna)
          // root->insertKey(*it);
          rightNode->parent = this;
        }
        // se apeleaza functia pentru rightNode (in functie, daca s-a facut compararea cu radacina)
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
          return NULL;
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
        //return nullptr;
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

