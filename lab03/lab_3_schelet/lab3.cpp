/**
 * LabSD 3
 * lab3.cpp
 * Purpose: Driver program to run lab3 tasks.
 *
 * @author Gabriel Bercaru
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "Algorithms.h"
#include "DoublyLinkedList.h"
#include "ResizableArray.h"
#include "SlidingWindow.h"

void checkDoublyLinkedList() {
	std::ofstream task1("Out/Lab3/task1.out");
	DoublyLinkedList<int> dll;

    std::cout << "========== Checking doubly linked list methods  ==========\n";

	dll.addLast(4);
    dll.addLast(3);
    dll.addLast(2);
    dll.addLast(1);

    dll.addFirst(-1);
    dll.addFirst(-2);
    dll.addFirst(-3);
    dll.addFirst(-4);

    std::cout << dll << std::endl;
    task1 << dll << std::endl;

    dll.removeFromPos(7);

    std::cout << dll << std::endl;
    task1 << dll << std::endl;
}

void checkResizableArray() {
	std::ofstream task2("Out/Lab3/task2.out");
	ResizableArray<int> ra;

	std::cout << "========== Checking resizable array methods ==========\n";

	ra.addLast(1);
    ra.addLast(100);
    ra.addLast(110);
    ra.addLast(51);
    ra.addFirst(2);
    ra.addFirst(17);
    ra.addFirst(5);

    std::cout << ra << std::endl;
    task2 << ra << std::endl;

    ra.removeFirst();
    ra.removeLast();

    std::cout << "Resizable array after removal of some elements: " << ra
        << std::endl;
    task2 << ra << std::endl;

    int retVal = ra.removeFromPos(2);

    std::cout << "Removed " << retVal << " from pos 2" << std::endl;
    task2 << retVal << std::endl;

    ra.addOnPos(999, 3);

    std::cout << "Resizable array after adding 999 on pos 3" << std::endl;
    task2 << ra << std::endl;
}

void checkSinglyLinkedListSort() {
	std::ofstream task3("Out/Lab3/task3.out");

	std::cout << "========== Singly linked list sort test ==========\n";

    DoublyLinkedList<int> unsorted;
    for (int i = 0; i < 7; i++) {
        unsorted.addFirst(i);
    }
    std::cout << "Unsorted: " << unsorted << std::endl;
    task3 << "Unsorted: " << unsorted << std::endl;

    Node<int> *sortedHead = Algorithms<int>::sort(unsorted.getHead());

    std::cout << "Sorted: ";
    task3 << "Sorted: ";
    if (sortedHead == nullptr) {
        std::cout << "[ ]";
        task3 << "[ ]";
    } else {
        std::cout << "[ ";
        task3 << "[ ";
        while (sortedHead->next != nullptr) {
            std::cout << sortedHead->data << " -> ";
            task3 << sortedHead->data << " -> ";
            sortedHead = sortedHead->next;
        }

        std::cout << sortedHead->data << " ]";
        task3 << sortedHead->data << " ]";
    }

    std::cout << std::endl;
}

void checkSinglyLinkedListReverse() {
	std::ofstream task4("Out/Lab3/task4.out");

	std::cout << "========== Singly linked list reverse test ==========\n";

    DoublyLinkedList<int> unreversed;
    for (int i = 0; i < 5; i++) {
        unreversed.addLast(i);
    }
    std::cout << "Unreversed: " << unreversed << std::endl;
    task4 << "Unreversed: " << unreversed << std::endl;

    Node<int> *reversedHead = Algorithms<int>::reverse(unreversed.getHead());

    std::cout << "Reversed: ";
    task4 << "Reversed: ";
    if (reversedHead == nullptr) {
        std::cout << "[ ]";
        task4 << "[ ]";
    } else {
        std::cout << "[ ";
        task4 << "[ ";
        while (reversedHead->next != nullptr) {
            std::cout << reversedHead->data << " -> ";
            task4 << reversedHead->data << " -> ";
            reversedHead = reversedHead->next;
        }
        std::cout << reversedHead->data << " ]";
        task4 << reversedHead->data << " ]";
    }
    std::cout << std::endl;
}

void checkSlidingWindow() {
	std::ofstream bonus1("Out/Lab3/bonus1.out");

	std::cout << "========== Sliding window (bonus) ==========\n";

    std::vector<int> container;
    for (int i = 0; i < 5; i++) {
        container.push_back(i + 1);
    }
    SlidingWindow<int> window(container, 3);

    std::cout << "Container: [ ";
    bonus1 << "Container: [ ";
    for (int i = 0; i < 5; i++) {
        std::cout << container[i] << " ";
        bonus1 << container[i] << " ";
    }
    std::cout << "]" << std::endl;
    bonus1 << "]" << std::endl;
    std::cout << "Window: " << window << std::endl;
    bonus1 << "Window: " << window << std::endl;

    for (int i = 0; i < 10; i++) {
        window.advance();
        std::cout << i + 1 << " / Window: " << window << std::endl;
        bonus1 << i + 1 << " / Window: " << window << std::endl;
    }
}

int main() {
    checkDoublyLinkedList();
    checkResizableArray();
    checkSinglyLinkedListSort();
    checkSinglyLinkedListReverse();
    checkSlidingWindow();

    return 0;
}
