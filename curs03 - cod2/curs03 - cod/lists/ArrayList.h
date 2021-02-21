#include <iostream>
using namespace std;

/*
 * cititi mai multe despre definirea claselor cu template in header aici:
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 */

template<class T>
class ArrayList {
    private:
        int size;
        int reallocSize;
        int count;
    public:
        T* L;
        ArrayList(){
          count = 0;
          size = 100;
          reallocSize = 10;
          L = new T[size];
        }

        ~ArrayList() {
          delete[] L;
        }

        void addLast(T x){
          if (count==size) {
          	 T* L2 = new T[size+reallocSize];
             for (int i=0; i<size; i++) {
          	     L2[i] = L[i];
             }
             delete[] L;
             L = L2;
             size+=reallocSize;
          }
          L[count++] = x;
        }

        T getElem(int index){
          return L[index];
        }

        /*
         * WARNING!! This is just a stub
         */
};
