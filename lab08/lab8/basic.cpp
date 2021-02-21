/**
  * Autor: Cosmin Petrisor
  * Echipa SD, 2015
  *
  * Modificari: Gabriel Bercaru, 2018
  *
  * License: LGPL
  */

#include <fstream>
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>

#include "BinaryTree.h"

using namespace std;

// Test constructor, destructor, setData, hasData, setLeftSubtree,
// getLeftSubtree, setRightSubtree, getRightSubtree, insertLeft, insertRight,
// insert
void test_ex1() {

#ifdef DEBUG
    std::ostream& task1_1 = std::cout;
    std::ostream& task1_2 = std::cout;
    std::ostream& task1_3 = std::cout;
#else
	std::ofstream f0;
	std::ofstream f1;
	std::ofstream f2;
    f0.open("Out/Lab8/task_1_1.out");
    f1.open("Out/Lab8/task_1_2.out");
    f2.open("Out/Lab8/task_1_3.out");
    std::ostream& task1_1 = f0;
    std::ostream& task1_2 = f1;
    std::ostream& task1_3 = f2;
#endif

	auto *root = new BinaryTree<int>();

	assert(!(root->hasData()));
	assert(root->getLeftSubtree() == nullptr);
	assert(root->getRightSubtree() == nullptr);

	task1_1 << "Constructor test .................................... passed.\n";

	root->setData(5);
	assert(root->hasData());

	task1_2 << "Set data test ....................................... passed.\n";

	root->setLeftSubtree(new BinaryTree<int>());
	root->setRightSubtree(new BinaryTree<int>());

	assert(root->getLeftSubtree() != nullptr &&
		   root->getRightSubtree() != nullptr);

	task1_2 << "Set subtrees test ................................... passed.\n";

	assert(!(root->getLeftSubtree()->hasData()));
	root->insertLeft(6);
	assert(root->getLeftSubtree()->hasData());

	assert(!(root->getRightSubtree()->hasData()));
	root->insertRight(8);
	assert(root->getRightSubtree()->hasData());

	task1_3 << "Insert left and right test .......................... passed.\n";

	root->insertRandomRecursively(4);

	BinaryTree<int> *node1 = root->getLeftSubtree()->getLeftSubtree();
	BinaryTree<int> *node2 = root->getLeftSubtree()->getRightSubtree();
	BinaryTree<int> *node3 = root->getRightSubtree()->getLeftSubtree();
	BinaryTree<int> *node4 = root->getRightSubtree()->getRightSubtree();

	assert(node1 || node2 || node3 || node4);

	task1_3 << "Random recursive insert test ........................ passed.\n";

	delete root;

#ifndef DEBUG
    f0.close();
    f1.close();
    f2.close();
#endif
}

// Test getTreeHeight, getNumNodes (you have to test displayTree by yourself)
void test_ex2() {

#ifdef DEBUG
    std::ostream& task2_1 = std::cout;
    std::ostream& task2_2 = std::cout;
    std::ostream& task2_3 = std::cout;
#else
    std::ofstream f0;
    std::ofstream f1;
    std::ofstream f2;
    f0.open("Out/Lab8/task_2_1.out");
    f1.open("Out/Lab8/task_2_2.out");
    f2.open("Out/Lab8/task_2_3.out");
    std::ostream& task2_1 = f0;
    std::ostream& task2_2 = f1;
    std::ostream& task2_3 = f2;
#endif

	auto *root = new BinaryTree<int>();
	root->setData(1);
	root->insertLeft(2);
	root->insertRight(3);
	root->getLeftSubtree()->insertLeft(4);
	root->getLeftSubtree()->insertRight(5);
	root->getRightSubtree()->insertRight(7);

	std::stringstream ss;
	std::streambuf *defaultStdout = std::cout.rdbuf(ss.rdbuf());
	root->displayTree(0);
    std::cout.rdbuf(defaultStdout);
	task2_1 << ss.str();

	cout << "\n\n";

	delete root;

	root = new BinaryTree<int>();

	assert(root->getTreeHeight() == 1);

	root->setData(5);
	root->insertRandomRecursively(1);
	assert(root->getTreeHeight() == 2);

	root->insertRandomRecursively(2);
	root->insertRandomRecursively(3);
	assert(root->getTreeHeight() > 2);

	task2_2 << "Tree height test .................................... passed.\n";

	delete root;
	/*
            1
          /   \
         2     3
        / \     \
       4   5     7
      / \
    10   8
     */

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

	BinaryTree<int>::getLCA(root2, leftLeftSubtree, rootRightSubtree);

	assert(BinaryTree<int>::getLCA(root2, leftLeftSubtree, rootRightSubtree) == root2);

	leftLeftSubtree->insertLeft(10);
	leftLeftSubtree->insertRight(8);
	auto left3Subtree = leftLeftSubtree->getLeftSubtree();
	auto leftRightSubtree = rootLeftSubtree->getRightSubtree();
	assert(BinaryTree<int>::getLCA(root2, left3Subtree, leftRightSubtree) == rootLeftSubtree);

	task2_3 << "LCA test ............................................ passed.\n";

	delete root2;

#ifndef DEBUG
    f0.close();
    f1.close();
    f2.close();
#endif
}

void test_ex3() {

#ifdef DEBUG
    std::ostream& task3_1 = std::cout;
    std::ostream& task3_2 = std::cout;
    std::ostream& task3_3 = std::cout;
#else
    std::ofstream f0;
    std::ofstream f1;
    std::ofstream f2;
    f0.open("Out/Lab8/bonus_3_1.out");
    f1.open("Out/Lab8/bonus_3_2.out");
    f2.open("Out/Lab8/bonus_3_3.out");
    std::ostream& task3_1 = f0;
    std::ostream& task3_2 = f1;
    std::ostream& task3_3 = f2;
#endif

	auto *root = new BinaryTree<int>();
	root->setData(1);
	root->insertLeft(2);
	root->insertRight(3);
	root->getLeftSubtree()->insertLeft(4);
	root->getLeftSubtree()->insertRight(5);
	root->getRightSubtree()->insertRight(7);

	vector<int> topView = root->topView();
	vector<int> bottomView = root->bottomView();
	vector<int> sideView = root->sideView();

	/*
    if (!topView.empty()) {
		cout << "Top view display (check for youself if it's correct):\n";
		int size = topView.size();

		for (int i = 0; i < size; ++i) {
			cout << topView[i] << ' ';
		}
	}
    */

	/*
    if (!bottomView.empty()) {
		cout << "Bottom view display (check for youself if it's correct):\n";
		int size = bottomView.size();

		for (int i = 0; i < size; ++i) {
			cout << bottomView[i] << ' ';
		}
	}
    */

	if (!sideView.empty()) {
		int size = sideView.size();

		for (int i = 0; i < size; ++i) {
			task3_1 << sideView[i] << ' ';
		}
	}
	cout << "\n\n";

	auto *root2 = new BinaryTree<int>();
	root2->setData(1);
	root2->insertLeft(2);
	root2->insertRight(3);
	root2->getLeftSubtree()->insertLeft(4);
	root2->getLeftSubtree()->insertRight(5);
	root2->getRightSubtree()->insertRight(7);

	assert(root->isIdentical(root2));
	task3_2 << "Identity test ....................................... passed.\n";
	delete(root2);

	auto *root3 = new BinaryTree<int>();
	root3->setData(1);
	root3->insertLeft(3);
	root3->insertRight(2);
	root3->getRightSubtree()->insertRight(4);
	root3->getRightSubtree()->insertLeft(5);
	root3->getLeftSubtree()->insertLeft(7);

	assert(root->isSymmetric(root3));
	task3_2 << "Symmetry test ....................................... passed.\n";
	delete(root3);

	vector<int> firstLevel = root->getLevel(0);
	assert(firstLevel.size() == 1 && firstLevel[0] == 1);

	vector<int> thirdLevel = root->getLevel(2);
	vector<int> thirdLevelTest = {4, 5, 7};
	for (int i = 0; i < 3; ++i) {
		assert(thirdLevel[i] == thirdLevelTest[i]);
	}
	task3_3 << "Level order traversal................................ passed.\n";

#ifndef DEBUG
    f0.close();
    f1.close();
    f2.close();
#endif
}

int main() {
	test_ex1();
	test_ex2();
	test_ex3();

	return 0;
}
