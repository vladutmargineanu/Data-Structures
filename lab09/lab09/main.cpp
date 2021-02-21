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

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cassert>

#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "Heap.h"

void baseFuntions(int nNumbers, std::vector<int> numbers, BinarySearchTree<int> *root) {
#ifdef DEBUG
    std::ostream& out1 = std::cout;
#else
    std::ofstream file1;
    file1.open("Out/Lab9/task1.out");
    std::ostream& out1 = file1;
#endif

    int key;
    for (int i=0;i<2;i++)
    {
        int pos=nNumbers - i*2 - 1;
        key=numbers[pos];
        if (root->searchKey(key)) {
            out1<<"Element "<<key<<" found"<<std::endl;
        } else {
            out1<<"[ERROR]Element "<<key<<" not found"<<std::endl;
        }
    }
    key=100;
    if (root->searchKey(key)) {
        out1<<"Element "<<key<<" found"<<std::endl;
    } else {
        out1<<"Element "<<key<<" not found"<<std::endl;
    }
    
    std::vector<int> display = root->inOrderDisplay();
    for (int elem : display) {
        out1<<elem<<" ";
    }

#ifndef DEBUG
    file1.close();
#endif
}

void findMinMax(BinarySearchTree<int> *root) {
#ifdef DEBUG
    std::ostream& out2 = std::cout;
#else
    std::ofstream file2;
    file2.open("Out/Lab9/task2.out");
    std::ostream& out2 = file2;
#endif

    out2<<"Min element: "<<root->findMin()<<std::endl;
    out2<<"Max element: "<<root->findMax()<<std::endl;

#ifndef DEBUG
    file2.close();
#endif
}

void findDisplayLevels(BinarySearchTree<int> *root) {
#ifdef DEBUG
    std::ostream& out3 = std::cout;
#else
    std::ofstream file3;
    file3.open("Out/Lab9/task3.out");
    std::ostream& out3 = file3;
#endif

    int nLevels=root->findLevels();
    out3<<"Tree has "<<nLevels<<" levels"<<std::endl;
    for (int i=0;i<nLevels;i++) {
        std::vector<int> dl = root->displayLevel(i);
        for (int elem : dl) {
            out3<<elem<<" ";
        }
        out3<<std::endl;
    }

#ifndef DEBUG
    file3.close();
#endif
}

void removeGivenKeys(std::vector<int> numbers, BinarySearchTree<int> *root) {
#ifdef DEBUG
    std::ostream& out4 = std::cout;
#else
    std::ofstream file4;
    file4.open("Out/Lab9/task4.out");
    std::ostream& out4 = file4;
#endif

    int key;
    for (int i=0;i<2;i++)
    {
        int pos=i+2;
        key=numbers[pos];
        root=root->removeKey(key);
        if (root->searchKey(key)) {
            out4<<"[ERROR]Element "<<key<<" found. "<<std::endl;
        } else {
            out4<<"Element "<<key<<" not found"<<std::endl;
        }
        std::vector<int> display = root->inOrderDisplay();
        for (int elem : display) {
            out4<<elem<<" ";
        }
        out4<<std::endl;
    }
    std::cout << std::endl;

#ifndef DEBUG
    file4.close();
#endif
}

void checkIsBST() {
#ifdef DEBUG
    std::ostream& out5 = std::cout;
#else
    std::ofstream file5;
    file5.open("Out/Lab9/task5.out");
    std::ostream& out5 = file5;
#endif

    auto *root2 = new BinaryTree<int>();
    root2->setData(1);
    root2->insertLeft(2);
    root2->insertRight(3);
    auto rootLeftSubtree = root2->getLeftSubtree();
    rootLeftSubtree->insertLeft(4);
    rootLeftSubtree->insertRight(5);
    auto rootRightSubtree = root2->getRightSubtree();
    rootRightSubtree->insertRight(7);
    auto leftLeftSubtree = rootLeftSubtree->getLeftSubtree();
    leftLeftSubtree->insertLeft(10);
    leftLeftSubtree->insertRight(8);

    if (!(BinaryTree<int>::isBST(root2))) {
        out5<<"Passed"<<std::endl;
    } else {
        out5<<"Failed"<<std::endl;
    }
    delete root2;

    auto *root3 = new BinaryTree<int>();
    root3->setData(7);
    root3->insertLeft(3);
    root3->insertRight(15);

    root3->getLeftSubtree()->insertLeft(1);
    root3->getLeftSubtree()->insertRight(4);

    root3->getRightSubtree()->insertLeft(9);
    root3->getRightSubtree()->insertRight(18);

    assert(BinaryTree<int>::isBST(root3));
    if (BinaryTree<int>::isBST(root3)) {
        out5<<"Passed"<<std::endl;
    } else {
        out5<<"Failed"<<std::endl;
    }
    delete root3;

#ifndef DEBUG
    file5.close();
#endif
}

void checkHeap() {
#ifdef DEBUG
    std::ostream& outb = std::cout;
#else
    std::ofstream fileb;
    fileb.open("Out/Lab9/bonus1.out");
    std::ostream& outb = fileb;
#endif
    std::ofstream bonus1("Out/Lab9/bonus1.out");

    Heap<int> heap(10);

    heap.insert(23);
    heap.insert(12);
    heap.insert(76);

    outb << heap.peek() << std::endl;
    heap.extractMin();
    outb << heap.peek() << std::endl;

#ifndef DEBUG
    fileb.close();
#endif
}

int main(int argc,char** argv)
{
    if (argc!=2)
    {
        std::cerr<<"Usage: "<<argv[0]<<" inputFile"<<std::endl;
        exit(0);
    }
    // Open file
    std::ifstream in(argv[1],std::ios::in);
    if (!in.is_open())
    {
        std::cerr<<"Invalid input file:"<<argv[0]<<std::endl;
        exit(0);
    }
    
    // Read data from file
    int nNumbers;
    in>>nNumbers;
    std::vector<int> numbers;
    for (int i=0;i<nNumbers;i++)
    {
        int nReadNumber;
        in>>nReadNumber;
        numbers.push_back(nReadNumber);
    }
    in.close();
    
    // Insert numbers in BST
    BinarySearchTree<int> *root=new BinarySearchTree<int>();
    for (std::vector<int>::iterator it=numbers.begin();it!=numbers.end();it++)
    {
        root->insertKey(*it);
    }

    baseFuntions(nNumbers, numbers, root);
    findMinMax(root);
    findDisplayLevels(root);
    // removeGivenKeys(numbers, root);
    // delete root;

     checkIsBST();
    checkHeap();

    return 0;
}
