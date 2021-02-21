#include <iostream>
using namespace std;

/*
 * cititi mai multe despre definirea claselor cu template in header aici:
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 */
 
template<typename T>
struct list_elem {
    T info;
    struct list_elem<T> *next;
};

template <typename T>
class LinkedList {
    private:
        struct list_elem<T> *first, *last;
    public:
      LinkedList(){
        first = last = NULL;
      }

      ~LinkedList(){
        while (first!=NULL) {
          struct list_elem<T> *aux = first;
          first = first->next;
          delete aux;
        }
      }

      void addLast(T x){
        struct list_elem<T>* newElem = new struct list_elem<T>;
        newElem->info = x;
        newElem->next = NULL;

        if (first==NULL) {
          first = last = newElem;
        } else {
          last->next = newElem;
          last = newElem;
        }
      }

      T getElem(int index){
        int count = 0;
        struct list_elem<T> *aux = first;
        while (aux!=NULL && count<index) {
          aux = aux->next;
          count++;
        }
        if (aux==NULL) return T();
        return aux->info;
      }

      /*
       * WARNING!! This is just a stub
       */

};
