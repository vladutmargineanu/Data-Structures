/**
 * LabSD 3
 * SlidingWindow.h
 * Purpose: Skeleton code for the sliding window.
 *
 * @author Gabriel Bercaru
 */

#ifndef __SLIDINGWINDOW_H__
#define __SLIDINGWINDOW_H__

#include <vector>

#include "DoublyLinkedList.h"

template <typename T>
class SlidingWindow {
private:
    int capacity;
    std::vector<T> container;
    DoublyLinkedList<T> window;

public:
    /**
     * Constructor. Initializes a new sliding window
     * based on the given vector. The window
     * will contain at most `capacity` elements.
     */
    SlidingWindow(const std::vector<T> container, int capacity) {
        // TODO: BONUS 1
    }

    ~SlidingWindow() {
        // TODO: delete previously allocated stuff (if any)
    }

    /**
     * Makes the window advance one position further.
     * 
     * @return A pointer to the new window head node.
     */
    Node<T> *advance() {
        // TODO: BONUS 1
        return nullptr;
    }

    // Getter
    Node<T> *getWindowHead() {
        return window.getHead();
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,
            SlidingWindow<U>& window);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, SlidingWindow<T>& window) {
    Node<T> *it = window.getWindowHead();

    os << "[ ";
    while (it != nullptr) {
        os << it->data << " ";
        it = it->next;
    }
    os << "]";

    return os;
}

#endif // __SLIDINGWINDOW_H__
