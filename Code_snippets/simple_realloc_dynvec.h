#ifndef __SIMPLE_REALLOC_DYNVEC
#define __SIMPLE_REALLOC_DYNVEC

#include <stdlib.h>
#include "dynvec.h"

template<typename T> class SimpleReallocDynamicVector: public DynamicVector<T> {
	private:
		T *v;
		int vsize;

	public:
		SimpleReallocDynamicVector() : DynamicVector<T>() {
			vsize = 0;
			v = NULL;
		}
	
		void add_last(T element) {
			vsize++;
			if (v == NULL) {
			//	v = (T*) malloc(vsize * sizeof(T));
				v = new T[vsize];
			} else {
				v = (T*) realloc(v, vsize * sizeof(T));
			}
			
			memcpy(/*v + (vsize - 1)*/ &v[vsize - 1], &element, sizeof(T));
			//v[vsize - 1] = element;
		}
		
		void remove_last() {
			if (vsize > 0) {
				vsize--;
				if (vsize == 0) {
					delete v;
					v = NULL;
				} else {
					v = (T*) realloc(v, vsize * sizeof(T));
				}
			}
		}
		
		int get_element(int position, T& element) {
			if (position < 0 || position >= vsize)
				return 0;
			memcpy(&element, v + position, sizeof(T));
			//element = v[position];
			return 1;
		}

		int set_element(int position, T element) {
			if (position < 0 || position >= vsize)
				return 0;
			memcpy(v + position, &element, sizeof(T));
			//v[position] = element;
			return 1;
		}

		int size() {
			return vsize;
		}
};

#endif
