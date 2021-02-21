/**
 * LabSD 4
 * DoubleQueueStack.h
 * Purpose: Skeleton code for the double queue stack.
 *
 * @author Gabriel Bercaru
 */

#ifndef __DOUBLEQUEUESTACK_H__
#define __DOUBLEQUEUESTACK_H__

#include <iostream>

template <typename T, int N>
class DoubleQueueStack {
private:
    int numElements;

    Queue<T, N> *q1;
    Queue<T, N> *q2;

public:
    // Constructor
    DoubleQueueStack() {
        // TODO: initializations
    }

    // Destructor
    ~DoubleQueueStack() {
        // TODO: delete previously allocated stuff (if any)
    }

    /**
     * Adds the given element on top of the stack.
     *
     * @param element Element to be added to the stack.
     */
    void push(T element) {
        // TODO: BONUS 2
    }

    /**
     * Removes the top element off the stack.
     */
    void pop() {
        // TODO: BONUS 2
    }

    /**
     * Returns the top element.
     *
     * @return Value of the element stored on top of the stack.
     */
    T peek() {
        // TODO: BONUS 2
        return 0;
    }

    /**
     * Checks if the stack contains any elements.
     *
     * @return True if the stack contains no elements, False otherwise.
     */
    bool isEmpty() {
        // TODO: BONUS 2
        return true;
    }

    /**
     * Returns the number of elements currently stored in the stack.
     *
     * @return The number of elements stored in the stack.
     */
    int size() {
        // TODO: BONUS 2
        return 0;
    }

    // Getters
    Queue<T, N> *getQ1() {
        return q1;
    }

    Queue<T, N> *getQ2() {
        return q2;
    }

    template <typename U, int M>
    friend std::ostream& operator<<(std::ostream& os,
            DoubleQueueStack<U, M>& stack);
};

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, DoubleQueueStack<T, N>& stack) {
    os << "Bottom to top: ";
    Queue<T, 10> *q1 = stack.getQ1();
    Queue<T, 10> auxQueue;

    while (!q1->isEmpty()) {
        os << q1->front() << " ";
        auxQueue.enqueue(q1->dequeue());
    }
    while (!auxQueue.isEmpty()) {
        q1->enqueue(auxQueue.dequeue());
    }

    return os;
}

#endif // __DOUBLEQUEUESTACK_H__
