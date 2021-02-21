/**
 * LabSD 4
 * Algorithms.h
 * Purpose: Wrapper class for Lab4 algorithms.
 *
 * @author Gabriel Bercaru
 */

#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#include <string>
#include <vector>

#include "Queue.h"
#include "Stack.h"

class Algorithms {
public:
    /**
     * Checks if the input string represents a balanced parentheses sequence.
     *
     * @param str String representing the sequence of brackets to be checked.
     * @return True if the sequence of brackets is balanced, False otherwise.
     */
    static bool checkBalancedParentheses(std::string str) {
        // TODO: TASK 3
       Stack<char, 50> stk;
       int error = 0;
       for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            stk.push(str[i]);
        else if (stk.isEmpty()) {           
            error = 1; 
            return false;           // Empty stack
        } else {
            if ((str[i] == ')' && stk.peek() != '(') || 
                (str[i] == ']' && stk.peek() != '[') ||
                (str[i] == '}' && stk.peek() != '{')) {
        error = 1; 
        return false;           // Wrong paranthesis
      }
            stk.pop();
        }
    }
    if (!error && !stk.isEmpty())
        return false;                  // Stack not empty at the end
    else if (!error)
        return true;
    }

    /**
     * Apply radix sort on the given vector.
     * Does not return anything, the vector
     * given as parameter must contain the
     * sorted elements.
     *
     * @param v Vector of elements to be sorted.
     */
    static void radixSort(std::vector<int>& v) {
        // TODO: TASK 4

        Queue<int, 50> queue[10];
        int i;

        int rang;
    for(rang = 1; rang <= 3; rang++){
        for(i = 0; i < v.size(); i++){
           // for(j = 0; j <= 9; j++)
            
                //if(v[i] % nr / (nr/10) == j){
                    //queue[j].enqueue(v[i]);
           int pow = 0, last = 0;
           int curr = v[i];
           while(pow < rang && curr != 0){
            last = curr % 10;
            curr /= 10;
            pow++;

            }
            if(pow < rang) last = 0;
            queue[last].enqueue(v[i]);
           
            
        }
       int number = 0;
      for(i = 0; i < 10; i++){
        while(!queue[i].isEmpty()){
           
             v[number++] = queue[i].dequeue();
        }
      }

   
    } 

}

    /**
     * Reverses the given queue.
     * Does not return anything, the queue
     * given as parameeter must contain
     * the elements, in reverse order.
     *
     * @param queue Queue to be reversed.
     */
    template <typename T>
    static void reverseQueue(Queue<T, 20>& queue) {
        // TODO: BONUS 1
    }
};

#endif // __ALGORITHMS_H__
