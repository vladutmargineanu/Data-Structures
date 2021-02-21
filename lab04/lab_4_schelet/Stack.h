/**
 * LabSD 4
 * Stack.h
 * Purpose: Skeleton code for the stack.
 *
 * @author Gabriel Bercaru
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <assert.h>

#include <vector>

/**
 * First template parameter is the datatype of the elements to be stored.
 * Second template parameter is the maximum stack size.
 */
template <typename T, int N>
class Stack {
private:
    // Underlying array
    T stackArray[N];

    int topLevel;

public:
    // Constructor
    Stack() {
        // TODO: initializations
	topLevel = 0;
    }

    // Destructor
    ~Stack() {
        // TODO: delete previously allocated stuff (if any)
    }

    /**
     * Adds an element on top of the stack.
     *
     * @param element Element to be added to the stack.
     */
    void push(T element) {
        // TODO: implement
	//if(topLevel < N) {
		stackArray[topLevel++] = element;
	//}
    }

    /**
     * Removes the top element of the stack.
     */
    void pop() {
        // TODO: TASK 1
	if(!this->isEmpty()) {
		//T element = stackArray[topLevel--];
		//return element;
		topLevel--;
	}
    }

    /**
     * Retrieves the top value stored in the stack.
     *
     * @return Value of the element stored on top of the stack.
     */
    T peek() {
        // TODO: TASK 1
	if(!this->isEmpty()) {
		T element = stackArray[topLevel-1];
		return element;
	}       
	 return 0;
    }

    /**
     * Checks if the stack contains any elements.
     *
     * @return True if the stack contains no elements, False otherwise.
     */
    bool isEmpty() {
        // TODO: TASK 1
	return (!topLevel) ? true : false;
        //return true;
    }

    /**
     * Returns the number of elements currently stored in the stack.
     *
     * @return The number of elements stored in the stack.
     */
    int size() {
        // TODO: TASK 1
	return topLevel;
        return 0;
    }

    template <typename U, int M>
    friend std::ostream& operator<<(std::ostream& os, Stack<U, M>& stack);
};

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, Stack<T, N>& stack) {
    os << "Bottom to top: ";
    std::vector<T> aux;

    while (!stack.isEmpty()) {
        aux.push_back(stack.peek());
        stack.pop();
    }

    for (int i = aux.size() - 1; i >= 0; i--) {
        os << aux[i] << " ";
        stack.push(aux[i]);
    }

    return os;
}

#endif // __STACK_H__
