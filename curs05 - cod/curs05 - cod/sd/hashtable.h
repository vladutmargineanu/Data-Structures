#include "linked_list.h"

template<typename Tkey, typename Tvalue> struct elem_info {
    Tkey key;
    Tvalue value; };

template<typename Tkey, typename Tvalue> class Hashtable {
    private:
        LinkedList<struct elem_info<Tkey, Tvalue> > *H;
        int HMAX;
        int (*hash) (Tkey);

    public:
        Hashtable(int hmax, int (*h) (Tkey)) {
            HMAX = hmax;
            hash = h;
            H = new LinkedList<struct elem_info<Tkey, Tvalue> > [HMAX]; 
        }

        ~Hashtable() {
            for (int i = 0; i < HMAX; i++) {
                 while (!H[i].isEmpty())
                    H[i].removeFirst();
            }

            delete[] H;
        }

        void put(Tkey key, Tvalue value) {
           struct list_elem<struct elem_info<Tkey, Tvalue> > *p;
           struct elem_info<Tkey, Tvalue> info;

           int hkey = hash(key);
           p = H[hkey].front();

           while (p != NULL) {  // operator == must be meaningful                    
                if (p->info.key == key) break;
                p = p->next;
           }

           if (p != NULL)
               p->info.value = value;
           else {
               info.key = key;
               info.value = value;
               H[hkey].addLast(info);
           }
       }

        Tvalue get(Tkey key) {
            struct list_elem<struct elem_info<Tkey, Tvalue> > *p;

            int hkey = hash(key);
            p = H[hkey].front();

            while (p != NULL) {
                if (p->info.key == key) break;
                p = p->next;
            }

            if (p != NULL)
                return p->info.value;
            else {
                fprintf(stderr, "Error 101 - The key does not exist\n");
                Tvalue x;
                return x;
            }
        }

        int hasKey(Tkey key) {
            struct list_elem<struct elem_info<Tkey, Tvalue> > *p;

            int hkey = hash(key);
            p = H[hkey].front();

            while (p != NULL) {
                if (p->info.key == key)
                    break;
                p = p->next;
            }

            if (p != NULL)
                return 1;
            else
                return 0;
        }

        int getCollisions() {
            int collisions = 0;
            for (int i = 0; i < HMAX; i++) {
                int size = H[i].size();
                if (size>1)
                  collisions += size-1;
            }
            return collisions;
        }

        int getMaxCollisions() {
            int maxCollisions = 0;
            for (int i = 0; i < HMAX; i++) {
                int size = H[i].size();
                if ((size-1)>maxCollisions)
                  maxCollisions = size-1;
            }
            return maxCollisions;
        }


};


