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

#ifndef HEAP_H
#define HEAP_H

#include<iostream>
 
template <typename T>
class Heap
{ 
private:
    T* values;
    int numberOfElemets;
    int capacity;
public:
    Heap(int capacity) {
        // TODO BONUS
      this->capacity = capacity;
      values = new T[capacity + 1];
      numberOfElemets = 0;
    }
    ~Heap() {
        // TODO BONUS
      delete[] values;
    }

    int parent(int poz) {
        // TODO BONUS
        return -1;
    }
 
    int leftSubtree(int poz) {
        // TODO BONUS
        return -1;
    }
 
    int rightSubtree(int poz) {
        // TODO BONUS
        return -1;
    }
 
    void pushUp(int poz) {
        // TODO BONUS
      if(poz > 1){
        int parent = poz/2;
        if(values[parent] > values[poz]){
          T aux = values[parent];
          values[parent] = values[poz];
          values[poz] = aux;
          pushUp(parent);
        }
      }
    }
 
    void pushDown(int poz) {
        // TODO BONUS
      int left = 2 * poz;
      int right = 2 * poz + 1;
      if(values[left] < values[poz] && left <= numberOfElemets){
        T aux = values[left];
        values[left] = values[poz];
        values[poz] = aux;
        pushDown(left);
      }
      if(values[right] > values[poz] && right <= numberOfElemets){
        T aux = values[right];
        values[right] = values[poz];
        values[poz] = aux;
        pushDown(right);
      }
    }
 
    void insert(T x) {
        // TODO BONUS
      values[numberOfElemets + 1] = x;
      numberOfElemets++;
      pushUp(numberOfElemets);
    }
 
    T peek() {
        // TODO BONUS
        return values[1];
    }
 
    T extractMin() {
        // TODO BONUS
      T value =  values[1];
      values[1] = values[numberOfElemets];
      numberOfElemets--;
      pushDown(1);
        return value;
    }
};

#endif // HEAP_H
