#ifndef __SGT_H_
#define __SGT_H_

#include "global_rebuilding_bst.h"

// Utilizat pentru a decide daca un subarbore este dezechilibrat sau nu.
#define SGT_MULTIPLIER 2.0

template<typename T> class ScapegoatTreeNode {
	public:
		ScapegoatTreeNode<T> *left_son, *right_son, *parent;
		T info;
		T (*compare)(T, T);
		int h, size;

		// Este 1 daca informatia din nodul curent a fost steara logic si 0 altfel.
		char removed;

		// Numarul de noduri sterse logic din subarborele cu radacina in nodul curent.
		int num_removed;
		
		ScapegoatTreeNode(int (*compare)(T, T), T info) {
            left_son = right_son = parent = NULL;
			this->compare = compare;
			memcpy(&(this->info), &info, sizeof(T));
			h = 0;
			size = 1;
			removed = 0;
			num_removed = 0;
		}

		// Insereaza informatia in arbore.
		// Intoarce un pointer catre cel mai adanc nod din arbore de pe calea de inserare
		// pentru care se incalca conditia de echilibru. Acest nod va trebui reechilibrat.
        virtual ScapegoatTreeNode<T>* insert_info(T x) {
			if (removed && compare(info, x) == 0) {
				// Refolosim un nod ce a fost sters logic anterior si contine aceeasi valoare
				// ca si valoarea noua ce se doreste a fi inserata.
				removed = 0;
				ScapegoatTreeNode<T>* node = this;
				while (node != NULL) {
					node->num_removed--;
					node = node->parent;
				}
				return NULL;
			} else {
				int next_son;
				if (compare(x, info) <= 0)
					next_son = 0;
				else
					next_son = 1;
	
				ScapegoatTreeNode<T>* result = NULL;
				
				if (next_son == 0) {  // left son
					if (left_son == NULL) {
						left_son = new ScapegoatTreeNode<T>(compare, x);
						left_son->parent = this;
						result = NULL;
					} else
						result = left_son->insert_info(x);
				} else { // right son
					if (right_son == NULL) {
						right_son = new ScapegoatTreeNode<T>(compare, x);
						right_son->parent = this;
						result = NULL;
					} else
						result = right_son->insert_info(x);
				}
				update_node_values(0);
	
				// Decide daca subarborele nodului curent este dezechilibrat.
				int unbalanced = (h > (int) ceil(SGT_MULTIPLIER * log2(size)));
				if (unbalanced && result == NULL) {
					// Daca e cel mai adanc nod dezechilibrat de pe calea de inserare,
					// atunci intoarce acest nod ca rezultat.
					result = this;
				}
				return result;
			}
        }

		// Intoarce un pointer catre nodul de contine informatia si NULL altfel.
        virtual ScapegoatTreeNode<T>* find_info(T x) {
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
            ScapegoatTreeNode<T> *t = find_info(x);
            if (t != NULL)
                return t->remove_self();
			else
				return 0;
        }

		void update_node_values(int propagate_up) {
			size = 1;

			if (!removed)
				num_removed = 0;
			else
				num_removed = 1;
			h = 0;

			if (left_son != NULL) {
				size += left_son->size;
				h = 1 + left_son->h;
				num_removed += left_son->num_removed;
			}
			if (right_son != NULL) {
				size += right_son->size;
				if (1 + right_son->h > h)
					h = 1 + right_son->h;
				num_removed += right_son->num_removed;
			}
			if (propagate_up && parent != NULL)
				parent->update_node_values(propagate_up);
		}

		// Intoarce 1 daca e stearsa radacina arborelui si 0 altfel.
		virtual int remove_self() {
			removed = 1;
			ScapegoatTreeNode<T>* node = this;
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

template<typename T, typename TreeNodeType> class ScapegoatTree: public GlobalRebuildingBinarySearchTree<T, TreeNodeType> {
	public:
		ScapegoatTree(int (*compare)(T, T)): GlobalRebuildingBinarySearchTree<T, TreeNodeType>(compare) {
		}

		virtual void insert_info(T x) {
			if (root == NULL) {
				root = new TreeNodeType(compare, x);
			} else {
				TreeNodeType *unbalanced_node = root->insert_info(x);
				// Daca s-a obtinut un nod dezechilibrat in urma inserarii, atunci
				// vom reechilibra complet (prin refacere completa) doar subarborele
				// corespunzator acestui nod.
				if (unbalanced_node != NULL) {
					rebuild_sub_tree(unbalanced_node);
				}
			}
		}

		virtual void remove_info(T x) {
			if (root != NULL) {
				root->remove_info(x);
				// Daca numarul de noduri sterse logic este mai mare sau egal cu
				// jumatate din numarul total de noduri din arbore, atunci refacem
				// complet intregul arbore.
				if (get_number_of_OK_nodes() <= get_size() / 2) {
					rebuild_sub_tree(root);
				}
			}
		}
};

#endif
