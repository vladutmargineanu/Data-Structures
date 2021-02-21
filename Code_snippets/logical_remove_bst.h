#ifndef __LRBST_H
#define __LRBST_H

#include <math.h>

template<typename T> class LogicalRemoveBSTNode {
	public:
		LogicalRemoveBSTNode<T> *left_son, *right_son, *parent;
		T info;
		T (*compare)(T, T);
		int h, size;

		// Este 1 daca informatia din nodul curent a fost steara logic si 0 altfel.
		char removed;

		// Numarul de noduri sterse logic din subarborele cu radacina in nodul curent.
		int num_removed;

		LogicalRemoveBSTNode(int (*compare)(T, T), T info) {
            left_son = right_son = parent = NULL;
			this->compare = compare;
			memcpy(&(this->info), &info, sizeof(T));
			h = 0;
			size = 1;
			removed = 0;
			num_removed = 0;
		}

		// Insereaza informatia in arbore.
        virtual void insert_info(T x) {
			if (removed && compare(info, x) == 0) {
				// Refolosim un nod ce a fost sters logic anterior si contine aceeasi valoare
				// ca si valoarea noua ce se doreste a fi inserata.
				removed = 0;
				LogicalRemoveBSTNode<T>* node = this;
				while (node != NULL) {
					node->num_removed--;
					node = node->parent;
				}
			} else {
				int next_son;
				if (compare(x, info) <= 0)
					next_son = 0;
				else
					next_son = 1;
	
				if (next_son == 0) {  // left son
					if (left_son == NULL) {
						left_son = new LogicalRemoveBSTNode<T>(compare, x);
						left_son->parent = this;
					} else
						left_son->insert_info(x);
				} else { // right son
					if (right_son == NULL) {
						right_son = new LogicalRemoveBSTNode<T>(compare, x);
						right_son->parent = this;
					} else
						right_son->insert_info(x);
				}		
				update_node_values(0);
			}
        }

		// Intoarce un pointer catre nodul de contine informatia si NULL altfel.
        virtual LogicalRemoveBSTNode<T>* find_info(T x) {
            if (!removed && compare(x, info) == 0)
                return this;

            if (compare(x, info) <= 0) {
                if (left_son != NULL)
                    return left_son->find_info(x);
                else
                    return NULL;
            } else {
                if (right_son != NULL)
                    return right_son->find_info(x);
                else
                    return NULL;
            }
        }

		// Sterge un element din arbore.
		// Intoarce 1 daca e stearsa radacina arborelui si 0 altfel.
        virtual int remove_info(T x) {
            LogicalRemoveBSTNode<T> *t = find_info(x);
            if (t != NULL)
                return t->remove_self();
			else
				return 0;
        }

		void update_node_values(int propagate_up) {
			size = 1;
			h = 0;
			if (left_son != NULL) {
				size += left_son->size;
				h = 1 + left_son->h;
			}
			if (right_son != NULL) {
				size += right_son->size;
				if (1 + right_son->h > h)
					h = 1 + right_son->h;
			}
			if (propagate_up && parent != NULL)
				parent->update_node_values(propagate_up);
		}

		// Intoarce 1 daca e stearsa radacina arborelui si 0 altfel.
		virtual int remove_self() {
			removed = 1;
			LogicalRemoveBSTNode<T>* node = this;
			while (node != NULL) {
				node->num_removed++;
				node = node->parent;
			}
			return 0;
        }

		// Un nod este OK daca informatia din el nu a fost stearsa logic.
		virtual int isOK() {
			return !removed;
		}
		
		// Intoarce numarul de noduri OK din subarborele cu radacina in nodul curent.
		virtual int get_number_of_OK_nodes() {
			return size - num_removed;
		}
		
		// Afisaza statistici despre nodul curent.
		virtual void print_statistics() {
			fprintf(stderr, "Inaltime: %d; Numar noduri: %d; Numar noduri sterse logic: %d\n", h, size, num_removed);
		}
};

#endif
