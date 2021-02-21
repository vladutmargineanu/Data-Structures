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
      leftNode = nullptr;
      rightNode = nullptr;
      pData = nullptr;
    }

    // Destructor TODO 1.1
    // Free up data for pData, left and right node
    ~BinaryTree() {

    }

    // Inspect if the current node has data. TODO 1.2
    bool hasData() {
        return false;
    }

    // Set data for current node. TODO 1.2
    void setData(T data) {

    }

    // Get current node's data. TODO 1.2
    T getData() {
        return T();
    }

    // Set left subtree. TODO 1.2
    void setLeftSubtree(BinaryTree<T> *node) {

    }

    // Get the left subtree. TODO 1.2
    BinaryTree<T> *getLeftSubtree() {
        return nullptr;
    }

    // Set right subtree. TODO 1.2
    void setRightSubtree(BinaryTree<T> *node) {

    }

    // Get the right subtree. TODO 1.2
    BinaryTree<T> *getRightSubtree() {
        return nullptr;
    }

    // Insert data recursively randomly where it is possible. TODO 1.3
    // compute a random value: 0 or 1.
    // http://www.cplusplus.com/reference/cstdlib/rand/
    // if 0 insert in left subtree like so:
    //   - if left subtree has data, then call insert recursively on it
    //   - else insert data into left node
    // else insert in right following exact same logic
    void insertRandomRecursively(T data) {

    }

    // Insert data into left subtree. TODO 1.3
    // If left node doesn't exist then allocate memory for it.
    // After that, set data on it.
    void insertLeft(T data) {

    }

    // Insert data into right subtree. TODO 1.3
    // If right node doesn't exist then allocate memory for it.
    // After that, set data on it.
    void insertRight(T data) {

    }

    // Display the binary tree to output. TODO 2.1
    void displayTree(int indentLevel) {

    }

    // Return the height of the binary tree. TODO 2.2
    int getTreeHeight() {
        return 0;
    }

    // Return the LCA of two nodes in the tree. TODO 2.3
    static BinaryTree<T>* getLCA(BinaryTree<T>* root, BinaryTree<T>* node1, BinaryTree<T>* node2) {
        return nullptr;
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


#endif // __BINARY_TREE_H
