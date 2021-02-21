#ifndef __BST_H
#define __BST_H

#include <string.h>

template<typename T> class BSTNode {
	public:
		// Pointeri catre fiul stanga, fiul drept si parinte.
        BSTNode<T> *left_son, *right_son, *parent;

		// Informatia utila.
        T info;
		
		// Functie ce compara 2 elemente de tipul T si intoarce < 0, = 0, > 0, daca primul
		// element este mai mic ca, egal cu, mai mare ca al doilea element. 
		int (*compare)(T, T);

		// h = inaltimea subarborelui cu radacina in nodul curent.
		// size = numarul de noduri din subarborele cu radacina in nodul curent.
		int h, size;

		// Constructor.
		BSTNode(int (*compare) (T, T), T info) {
            left_son = right_son = parent = NULL;
			this->compare = compare;
			memcpy(&(this->info), &info, sizeof(T));
			h = 0;
			size = 1;
        }

		// Insereaza informatia in arbore.
        virtual void insert_info(T x) {
            int next_son;
            if (compare(x, info) <= 0)
                next_son = 0;
            else
                next_son = 1;

            if (next_son == 0) {  // left son
                if (left_son == NULL) {
                    left_son = new BSTNode<T>(compare, x);
                    left_son->parent = this;
                } else
                    left_son->insert_info(x);
            } else { // right son
                if (right_son == NULL) {
                    right_son = new BSTNode<T>(compare, x);
                    right_son->parent = this;
                } else
                    right_son->insert_info(x);
            }
			update_node_values(0);
        }

		// Actualizeaza campurile h si size. Daca propagate_up este nenul, atunci se
		// apeleaza recursiv pentru toti stramosii nodului curent.
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

		// Intoarce un pointer catre nodul de contine informatia si NULL altfel.
        virtual BSTNode<T>* find_info(T x) {
            if (compare(x, info) == 0)
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
            BSTNode<T> *t = find_info(x);
            if (t != NULL)
                return t->remove_self();
			else
				return 0;
        }
		
		// Intoarce 1 daca e stearsa radacina arborelui si 0 altfel.
		virtual int remove_self() {
            BSTNode<T> *p;
            if (left_son == NULL && right_son == NULL) {
                if (parent == NULL) { // this == root
					delete this;
					return 1;
				} else {
                    if (parent->left_son == this)
                        parent->left_son = NULL;
                    else
                        parent->right_son = NULL;
					parent->update_node_values(1);
                    delete this;
					return 0;
                }
            } else {
                if (left_son != NULL) {
					// Gaseste nodul cu cea mai mare valoare din subarborele stang.
                    p = left_son;
                    while (p->right_son != NULL)
                        p = p->right_son;
                } else { // right_son != NULL
					// Gaseste nodul cu cea mai mica valoare din subarborele drept.
                    p = right_son;
                    while (p->left_son != NULL)
                        p = p->left_son;
                }

                memcpy(&info, &(p->info), sizeof(T));
                return p->remove_self();
            }
        }

		// Intoarce daca nodul este OK. Aceasta functie intoarce mereu 1 pentru
		// noduri de tipul BSTNode, dar va fi redefinita pentru alte tipuri de noduri.
		virtual int isOK() {
			return 1;
		}

		// Intoarce numarul de noduri OK din subarborele cu radacina in nodul curent.
		virtual int get_number_of_OK_nodes() {
			return size;
		}
		
		// Afisaza statistici despre nodul curent.
		virtual void print_statistics() {
			fprintf(stderr, "Inaltime: %d; Numar noduri: %d\n", h, size);
		}
};

// T = tipul elementelor stocate in arbore.
// TreeNodeType = tipul nodurilor arborelui (de ex., BSTNode<T>
// sau alte tipuri de noduri care implementeaza comportamente diferite).
template<typename T, typename TreeNodeType> class BinarySearchTree {
	public:
		TreeNodeType* root;
		int (*compare) (T, T);
		
		BinarySearchTree(int (*compare) (T, T)) {
			root = NULL;
			this->compare = compare;
		}
	
		// Insereaza un element nou in arbore.
		virtual void insert_info(T x) {
			if (root == NULL) {
				root = new TreeNodeType(compare, x);
			} else
				root->insert_info(x);
		}

		// Cauta un element in arbore.
		virtual TreeNodeType* find_info(T x) {
			if (root == NULL)
				return NULL;
			else
				return root->find_info(x);
		}

		// Sterge un element din arbore.
		virtual void remove_info(T x) {
			if (root != NULL) {
				if (root->remove_info(x)) {
					root = NULL;
				}
			}
		}

		// Intoarce inaltimea arborelui.
		virtual int get_h() {
			if (root != NULL)
				return root->h;
			return 0;
		}

		// Intoarce numarul de noduri din arbore.
		virtual int get_size() {
			if (root != NULL)
				return root->size;
			return 0;
		}
		
		// Intoarce numarul de noduri OK din arbore.
		virtual int get_number_of_OK_nodes() {
			if (root != NULL)
				return root->get_number_of_OK_nodes();
			return 0;
		}
		
		// Afisaza statistici.
		virtual void print_statistics() {
			if (root == NULL)
				fprintf(stderr, "arbore vid\n");
			else
				root->print_statistics();
		}
};

// Functie pentru compararea a doua int-uri.
int compare_int(int a, int b) {
	return (a - b);
}

#endif
