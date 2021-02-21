#ifndef __SMART_REALLOC_DYNVEC
#define __SMART_REALLOC_DYNVEC

#include <stdlib.h>
#include "dynvec.h"

template<typename T> class SmartReallocDynamicVector: public DynamicVector<T> {
	private:
		T *v;
		int vsize, alloc_size;
		double add_multiplier, remove_multiplier;

	public:
		SmartReallocDynamicVector(double add_multiplier, double remove_multiplier) : DynamicVector<T>() {
			vsize = alloc_size = 0;
			v = NULL;
			this->add_multiplier = add_multiplier;
			this->remove_multiplier = remove_multiplier;
		}
	
		void add_last(T element) {
			vsize++;
			if (v == NULL) {
				//v = (T*) malloc(vsize * sizeof(T));
				v = new T[vsize];
				alloc_size = vsize;
			} else if (vsize > alloc_size) {
				alloc_size = (int) (add_multiplier * alloc_size);
				v = (T*) realloc(v, alloc_size * sizeof(T));
			}
			memcpy(v + (vsize - 1), &element, sizeof(T));
			//v[vsize - 1] = element;
		}
		
		void remove_last() {
			if (vsize > 0) {
				vsize--;
				if (vsize == 0) {
					delete v;
					v = NULL;
					alloc_size = 0;
				} else if (vsize <= (int) (remove_multiplier * alloc_size)) {
					alloc_size = vsize;
					v = (T*) realloc(v, alloc_size * sizeof(T));
				}
			}
		}
		
		int get_element(int position, T& element) {
			if (position < 0 || position >= vsize)
				return 0;
			memcpy(&element, v + position, sizeof(T));
			return 1;
		}

		int set_element(int position, T element) {
			if (position < 0 || position >= vsize)
				return 0;
			memcpy(v + position, &element, sizeof(T));
			return 1;
		}

		int size() {
			return vsize;
		}
};

#endif
