/**
 * LabSD 3
 * ResizableArray.h
 * Purpose: Skeleton code for the resizable array.
 *
 * @author Gabriel Bercaru
 */

#ifndef __RESIZABLEARRAY_H__
#define __RESIZABLEARRAY_H__

#include <assert.h>

template <typename T>
class ResizableArray {
private:
    int defaultCapacity = 5;
    int expandFactor = 2;

    int numElements;
    int maxCapacity;
    T *data;

public:
    // Constructor
    ResizableArray() {
        numElements = 0;
        maxCapacity = defaultCapacity;

        data = new T[maxCapacity];
    }

    // Another constructor
    ResizableArray(int initialCapacity) {
        numElements = 0;
        maxCapacity = initialCapacity;

        data = new T[maxCapacity];
    }

    // Another constructor
    ResizableArray(int initialCapacity, int defaultFactor) {
        numElements = 0;
        maxCapacity = initialCapacity;
        expandFactor = defaultFactor;

        data = new T[maxCapacity];
    }

    // Destructor
    ~ResizableArray() {
        // TODO: delete previously allocated stuff (if any)
    }

    /**
     * Adds the specified element at the end of the array.
     *
     * @param element Element to be added at the end of the array.
     */
    void addLast(T element) {
        // TODO: implement
    }

    /**
     * Adds the specified element at the beginning of the array.
     *
     * @param element Elment to be added at the beginning of the array.
     */
    void addFirst(T element) {
        // TODO: TASK 2
    }

    /**
     * Removes and returns the last element of the array.
     *
     * @return Value of the last element stored in the array.
     */
    T removeLast() {
        // TODO: TASK 2
        return 0;
    }

    /**
     * Removes and returns the first element of the array.
     *
     * @return Value of the first element stored in the array.
     */
    T removeFirst() {
        // TODO: TASK 2
        return 0;
    }

    /**
     * Checks if the array contains any elements.
     *
     * @return True if the array contains no elements, False otherwise.
     */
    bool isEmpty() {
        // TODO: TASK 2
        return true;
    }

    /**
     * Returns the number of elements in the array.
     *
     * @return The number of elements stored in the array.
     */
    int size() {
        // TODO: TASK 2
        return 0;
    }

    /**
     * Adds the specified element on pos'th position of the array.
     *
     * @param element Element to be added on the specified position in the array.
     * @param pos Position on which the new element should be placed.
     */
    void addOnPos(T element, int pos) {
        // TODO: TASK 2
    }

    /**
     * Removes and returns the pos'th element of the array.
     *
     * @param pos Position from which to extract the element.
     * @return Value stored on pos'th position.
     */
    T removeFromPos(int pos) {
        // TODO: TASK 2
        return 0;
    }

    // Getters & Setters
    T *getData() {
        return data;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,
            const ResizableArray<U>& ra);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, ResizableArray<T>& ra) {
    os << "[ ";
    for (int i = 0; i < ra.size(); i++) {
        os << (ra.getData())[i] << " ";
    }
    os << "]";

    return os;
}

#endif // __RESIZABLEARRAY_H__
