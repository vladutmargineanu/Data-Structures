/**
 * LabSD 5
 * hash_element.h
 * Purpose: Hash functions for different types of keys.
 *
 * @author Ioana Stefan
 */

#ifndef __HASH_FUNCTIONS__H
#define __HASH_FUNCTIONS__H

#define INT_HASH	10
#define	STRING_HASH	8497

#include <string.h>

/* Basic hash function for integer keys. */
unsigned int hashingFunction(int nr){
    return nr % INT_HASH;
}

/* Basic hash function pt strings. */
unsigned int charHashingFunction(std::string str){
    return str.length() + STRING_HASH;
}

#endif // __HASH_FUNCTIONS__H