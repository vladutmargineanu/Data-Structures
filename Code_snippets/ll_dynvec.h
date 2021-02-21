#ifndef __LL_DYNVEC
#define __LL_DYNVEC

#include <string.h>
#include "dynvec.h"

template<typename T> struct list_elem {
	T info;
    struct list_elem<T> *next, *prev;
};

template <typename T> class LinkedListDynamicVector: public DynamicVector<T> {
	private:
		int vsize;
		
	public:
        struct list_elem<T> *pfirst, *plast;

        LinkedListDynamicVector(): DynamicVector<T>() {
            pfirst = plast = NULL;
			vsize = 0;
        }

        void add_last(T element) {
            struct list_elem<T> *paux;

            paux = new struct list_elem<T>;
            memcpy(&(paux->info), &element, sizeof(T));
            paux->prev = plast;
            paux->next = NULL;

            if (plast != NULL) plast->next = paux;
            plast = paux;
            if (pfirst == NULL) pfirst = plast;

			vsize++;
        }

        void remove_last() {
            struct list_elem<T> *paux;

            if (plast != NULL) {
                paux = plast->prev;
                if (pfirst == plast) pfirst = NULL;
                delete plast;
                plast = paux;
                if (plast != NULL) plast->next = NULL;
            }

			vsize--;
        }

        int get_element(int position, T& element) {
			if (position < 0 || position >= vsize)
				return 0;

            struct list_elem<T> *paux;
			int current_position = 0;

            paux = pfirst;
            while (paux != NULL && current_position != position) {
                paux = paux->next;
				current_position++;
            }

			memcpy(&element, &(paux->info), sizeof(T));
			//element = paux->info;
			return 1;
        }

		int set_element(int position, T element) {
			if (position < 0 || position >= vsize)
				return 0;

            struct list_elem<T> *paux;
			int current_position = 0;

            paux = pfirst;
            while (paux != NULL && current_position != position) {
                paux = paux->next;
				current_position++;
            }

			memcpy(&(paux->info), &element, sizeof(T));
			//paux->info = element;
			return 1;
		}

		int size() {
			return vsize;
		}
};
#endif
