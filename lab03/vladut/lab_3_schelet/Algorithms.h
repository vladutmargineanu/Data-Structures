/**
 * LabSD 3
 * Algorithms.h
 * Purpose: Wrapper class for Lab3 algorithms.
 *
 * @author Gabriel Bercaru
 */

#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#include "DoublyLinkedList.h"

template <typename T>
class Algorithms {
public:
    /**
     * Sort a non empty singly linked list.
     * You should also check if head is null.
     *
     * @param head First node of the list to be sorted.
     * @return pointer to the first node of the sorted list.
     */
    static Node<T> *sort(Node<T> *head) {
        // TODO: TASK 3
        if (head) {
           int k, count = 0;
           Node<T> *current, *prev;
           T data;
           do {
                k = 0;
                prev = head;

                // place myself on count element
                while (k != count && prev->next) {
                    prev = prev->next;
                    k++;
                }

                // sort
                k = 0;
                current = prev->next;
                while (current) {
                    if (current->data < prev->data) {
                        data = prev->data;
                        prev->data = current->data;
                        current->data = data;
                        k = 1;
                    }
                    current = current->next;
                }
                ++count;
           } while (k);
           return head;
        }
        return nullptr;
    }

    /**
     * Reverses the order of the elements in the linked
     * list pointed to by head.
     *
     * @param head First node of the list to be sorted.
     * @return pointer to the first node of the reversed list.
     */
    static Node<T> *reverse(Node<T> *head) {
        // TODO: TASK 4
        if (head->next) {
            Node<T> *nextNode = nullptr;
            Node<T> *prevNode = nullptr;
            Node<T> *currentNode;
            currentNode = head;
            while (currentNode) {
                nextNode = currentNode->next;
                currentNode->next = prevNode;
                prevNode = currentNode;
                currentNode = nextNode;
            }
            head = prevNode;
            prevNode = nullptr;
        }
        return head;
    }
};

#endif // __ALGORITHMS_H__
