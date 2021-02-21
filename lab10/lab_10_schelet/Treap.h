/* Laborator 10 SD - Treapuri
  * Autor: Andrei Parvu - andrei.parvu@cti.pub.ro
  * Echipa SD, 2014
  *
  * Modificari: Mihai Neacsu - mihai.mneacsu@gmail.com
  * Echipa SD, 2015
  *
  * Modificari: Gabriel Bercaru, 2018
 */

using namespace std;

template <typename T> struct Treap {
    T key;
    int priority;
    Treap<T> *left, *right;
    bool nil;

    // Pentru a rezolva problema 3 trebuie ca fiecare nod sa retina numarul de
    // noduri din subarborle sau
    int nr_nodes;

    // Creaza un nod nil
    Treap() : priority(-1), left(NULL), right(NULL), nil(true), nr_nodes(0) {}

    // Adaugam date, transformand un nod nil intr-un nod obisnuit
    void addData(T key, int priority) {
        this->nil = false;
        this->key = key;
        this->priority = priority;
        this->nr_nodes = 1;
        this->left = new Treap();
        this->right = new Treap();
    }

    // Stergem un nod obisnuit, transformandu-l intr-unul nil
    void delData() {
        this->nil = true;
        this->priority = -1;
        delete this->left;
        delete this->right;
        this->nr_nodes = 0;
    }

    bool isNil() {
        return this->nil;
    }

    bool find(T key) {

        if (this->isNil()) {
            return false;
        }
        if(this->key == key)
          return true;

        // TODO 1.1: Completati functia de cautare
        
        if(this->key < key){
            return this->right->find(key);
          }
        
        
        if(this->key > key){
          
            return this->left->find(key);
          
        }
        return false;
    }

    /* Atat insert cat si erase au nevoie de o referinta catre un fatherPointer,
       adica de pointerul left sau right din parinte care pointeaza catre obiectul
       curent. De ce?
       Sa presupunem ca avem urmatoarea configuratie:
                     a
                    / \
                   b   c
                      / \
                     d   e

       si facem o rotatie dreapta in nodul c. Configuratia care rezulta este:
                     a
                    / \
                   b   d
                        \
                         c
                          \
                           e

       Dupa cum se poat vedea pointerul right a lui a trebuie sa pointeze in urma
       rotirii catre d. De aceea, o referinta a acelui pointer trebuie pasata catre
       fiul care reprezinta acel pointer, pentru ca nodul a sa vada eventualele
       inlocuiri ce pot aparea in urma unor rotiri.
       Atentie! - desi s-ar putea sa spunem ca putem folosi pointerul this pentru
       a rezolva problema de mai sus, acest lucru este gresit, deoarece this este un
       pointer constant, asupra caruia nu se pot face asignari de forma this = ...
     */

    void rotateRight(Treap<T> *&fatherPointer) {
        // TODO 1.2: Completati rotirea dreapta

        // TODO 1.2: Recalculati dimensiunea subarborilor
      Treap<T>* left_node = fatherPointer->left;
      Treap<T>* right_child = left_node->right;
      

      left_node->right = fatherPointer;
      fatherPointer->left = right_child;
    }

    void rotateLeft(Treap<T> *&fatherPointer) {
   	    // TODO 1.2: Completati rotirea stanga

        // TODO 1.2: Recalculati dimensiunea subarborilor
      Treap<T>* right_node = fatherPointer->right;
      Treap<T>* left_child = right_node->left;
      
      right_node->left = fatherPointer;
      fatherPointer->right = left_child;
      
    }

    void insert(Treap<T> *&fatherPointer, T key, int priority) {
        if (this->isNil()) {
            this->addData(key, priority);
            return;
        }
       
       /* if (key <= this->key){

          this->left->insert(this->left, key, priority);
           nr_nodes++;

          if(this->left->priority > this->priority){
            
           rotateRight(this);
          }
        } else {
           this->right->insert(this->right, key, priority);
            nr_nodes++;
          if(this->right->priority > this->priority){
            rotateLeft(this);
          }
        }        
    }
    */
        Treap<T> *nonConstThis = this;

        // TODO 1.3: Inserati recursiv in arbore
        if (key < this->key) {
          nonConstThis->left->insert(nonConstThis->left, key, priority);

        } else {
          nonConstThis->right->insert(nonConstThis->right, key, priority);

        }

        nr_nodes++;

        // TODO 1.3: Faceti rotatiile corespunzatoare
        if (this->left->priority > this->priority) {
          
        nonConstThis->rotateRight(nonConstThis);

        } else if (this->right->priority > this->priority) {
        nonConstThis->rotateLeft(nonConstThis);

        }
    } 

    void erase(Treap<T> *&fatherPointer, T key) {
        if (this->isNil()) {
            return ;
        }

        Treap<T> *nonConstThis = this;
        nr_nodes--;

        // TODO 2: Stergti recursiv in arbore (pe subarborele corespunzator)
        if (key < this->key) {
          
        } else if (key > this->key) {

        } else if (this->left->isNil() && this->right->isNil()) {
            this->delData();
        } else {
            // TODO 2: Rotiti si stergeti recursiv pentru a aduce nodul la baza arborelui
            if (this->left->priority > this->right->priority) {

            } else {

            }
        }
    }

    void inOrder() {
        if (this->isNil()) {
            return ;
        }

        // TODO 3: Afisati parcurgerea inordine a cheilor
    }

    void preOrder(int level = 0) {
        if (this->isNil()) {
            return ;
        }

        for (int i = 0; i < level; i++) {
            cout << ' ';
        }

        // TODO 3: Afisati parcurgerea preordine a prioritatilor
    }

    T findK(int k) {
  	    // TODO 3: Pe baza nr_nodes determinati cea de-a k cheie in ordinea sortarii

        return 0;
    }
};
