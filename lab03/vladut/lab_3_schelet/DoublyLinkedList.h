/**
 * LabSD 3
 * DoublyLinkedList.h
 * Purpose: Skeleton code for the doubly linked list.
 *
 * @author Gabriel Bercaru
 */

#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include <assert.h>

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int numElements;

    /**
     * Returns the pos'th node in the list.
     */
    Node<T> *goToPos(int pos) {
        int count = 0;
        Node<T> *temp = head;

        while (count != pos) {
            temp = temp->next;
            count++;
        }

        return temp;
    }

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        numElements = 0;
    }

    // Another constructor
    DoublyLinkedList(Node<T> *head) {
        this->head = head;
        while (head != nullptr) {
            numElements++;
            head = head->next;
        }
    }

    // Destructor
    ~DoublyLinkedList() {
        // TODO: delete previously allocated stuff (if any)
        if (!this->isEmpty()) {
            Node<T> *aux;
            while (head) {
                aux = head;
                head = head->next;
                delete aux;;
            }
        }
    }

    /**
     * Adds a new node at the end of the list.
     *
     * @param data Data to be added at the end of the list.
     */
    void addLast(T data) {
        // TODO: TASK 1
        Node<T> *aux = new Node<T>(data);
        if (!tail) {
            head = tail = aux;
        } else {
            aux->prev = tail;
            tail->next = aux;
            tail = aux;
        }
        ++numElements;
    }

    /**
     * Adds a new node at the beginning of the list.
     *
     * @param data Data to be added at the beginning of the list.
     */
    void addFirst(T data) {
        // TODO: TASK 1
        Node<T> *aux = new Node<T>(data);
        if (!head) {
            head = tail = aux;
        } else {
            head->prev = aux;
            aux->next = head;
           // aux->prev = nullptr;
            head = aux;
        }
        ++numElements;
    }

    /**
     * Removes the last node of the list.
     *
     * @return Value stored in the last node of the list.
     */
    T removeLast() {
        // TODO: TASK 1
        if (!this->isEmpty()) {
            T data;
            data = tail->data;
            if (numElements == 1) {
                delete tail;
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }
            --numElements;
            return data;
        }
        return 0;
    }

    /**
     * Removes the first node of the list.
     *
     * @return Value stored in the first node of the list.
     */
    T removeFirst() {
        // TODO: TASK 1
        if (!this->isEmpty()) {
            T data;
            data = head->data;
            if (numElements == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
            }
            --numElements;
            return data;
        }
        return 0;
    }

    /**
     * Check if the list contains any elements.
     *
     * @return True if the list contains no elements, False otherwise.
     */
    bool isEmpty() {
        // TODO: TASK 1
        return (!head) ? true : false;
    }

    /**
     * Get the number of nodes in the list.
     *
     * @return The number of nodes stored in the list.
     */
    int size() {
        // TODO: TASK 1
        return numElements;
    }

    /**
     * Adds a new node on the specified position in the list.
     *
     * @param element Data to be added on the specified position in the list.
     * @param pos Position on which the new node should be placed.
     */
    void addOnPos(T element, int pos) {
        // TODO: TASK 1
        if (pos == 0) {
            this->addFirst();
        } else if (pos == numElements - 1) {
            this->addLast();
        } else if (pos > 0 && pos < numElements - 1) {
            Node<T> *curr = goToPos(pos);
            Node<T> *aux = new Node<T>(element);
            aux->prev = curr->prev;
            aux->next = curr;
            curr->prev->next = aux;
            curr->prev = aux;
        }
    }

    /**
     * Removes the node on the specified position and returns the value it stored.
     *
     * @param pos Position from which to extract the node.
     * @return Value stored in the node extracted.
     */
    T removeFromPos(int pos) {
        // TODO: TASK 1
        if (pos == 0) {
            this->removeFirst();
        } else if (pos == numElements - 1) {
            this->removeLast();
        } else if (pos > 0 && pos < numElements - 1) {
            Node<T> *aux;
            Node<T> *curr = goToPos(pos);
            aux = curr->next;
            aux->prev = curr->prev;
            aux = curr->prev;
            aux->next = curr->next;
            delete curr;
        }
        return 0;
    }

    // Getters & Setters
    Node<T> *getHead() {
        return head;
    }

    Node<T> *getTail() {
        return tail;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,
            DoublyLinkedList<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T>& list) {
    Node<T> *it = list.getHead();

    if (list.size() > 0) {
        os << "[ ";
        while (it->next != nullptr) {
            os << it->data << " <-> ";
            it = it->next;
        }

        os << it->data;
        os << " ]";
    } else {
        os << "[]";
    }

    return os;
}

#endif // __DOUBLYLINKEDLIST_H__
