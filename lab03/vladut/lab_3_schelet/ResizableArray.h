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
        if (!this->isEmpty()) {
            delete [] data;
        }
    }

    /**
     * Adds the specified element at the end of the array.
     *
     * @param element Element to be added at the end of the array.
     */
    void addLast(T element) {
        // TODO: implement
        if (numElements == maxCapacity) {
            maxCapacity *= expandFactor;
            T *aux = new T[maxCapacity];
            for (int i = 0; i < numElements; i++) {
                aux[i] = data[i];
            }
            delete [] data;
            data = aux;
        }

        data[numElements++] = element;
    }

    /**
     * Adds the specified element at the beginning of the array.
     *
     * @param element Elment to be added at the beginning of the array.
     */
    void addFirst(T element) {
        // TODO: TASK 2
        if (numElements == maxCapacity) {
            maxCapacity *= expandFactor;
            T *aux = new T[maxCapacity];
            for (int i = 0; i < numElements; i++) {
                aux[i + 1] = data[i];
            }
            delete [] data;
            data = aux;
        } else {
            for (int i = numElements - 1; i >= 0; i--) {
                data[i + 1] = data[i];
            }
        }
        ++numElements;
        data[0] = element;
    }

    /**
     * Removes and returns the last element of the array.
     *
     * @return Value of the last element stored in the array.
     */
    T removeLast() {
        // TODO: TASK 2
        if (!this->isEmpty()) {
            T element = data[numElements--];
            return element;
        }
        return 0;
    }

    /**
     * Removes and returns the first element of the array.
     *
     * @return Value of the first element stored in the array.
     */
    T removeFirst() {
        // TODO: TASK 2
        if (!this->isEmpty()) {
            T element = data[0];
            for (int i = 0; i < numElements - 1; i++) {
                data[i] = data[i + 1];
            }
            --numElements;
            return element;
        }
        return 0;
    }

    /**
     * Checks if the array contains any elements.
     *
     * @return True if the array contains no elements, False otherwise.
     */
    bool isEmpty() {
        // TODO: TASK 2
        return (!numElements) ? true : false;
    }

    /**
     * Returns the number of elements in the array.
     *
     * @return The number of elements stored in the array.
     */
    int size() {
        // TODO: TASK 2
        return numElements;
    }

    /**
     * Adds the specified element on pos'th position of the array.
     *
     * @param element Element to be added on the specified position in the array.
     * @param pos Position on which the new element should be placed.
     */
    void addOnPos(T element, int pos) {
        // TODO: TASK 2
        if (pos == 0) {
            this->addFirst(element);
        } else if (pos == numElements) {
            this->addLast(element);
        } else if (pos > 0 && pos < numElements) {
            if (numElements == maxCapacity) {
                maxCapacity *= expandFactor;
                T *aux = new T[maxCapacity];
                for (int i = numElements - 1; i > pos; i--) {
                    aux[i + 1] = data[i];
                }
                aux[pos + 1] = data[pos];
                aux[pos] = element;
                for (int i = pos - 1; i >= 0; i--) {
                    aux[i] = data[i];
                }
                delete [] data;
                data = aux;
            } else {
                for (int i = numElements - 1; i > pos; i--) {
                    data[i + 1] = data[i];
                }
                data[pos + 1] = data[pos];
                data[pos] = element;
            }
            ++numElements;
        }
    }

    /**
     * Removes and returns the pos'th element of the array.
     *
     * @param pos Position from which to extract the element.
     * @return Value stored on pos'th position.
     */
    T removeFromPos(int pos) {
        // TODO: TASK 2
        if (!this->isEmpty()) {
            T element = data[pos];
            for (int i = pos; i < numElements - 1; i++) {
                data[i] = data[i + 1];
            }
            --numElements;
            return element;
        }
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
