#ifndef __HASHTABLE__H
#define __HASHTABLE__H
#include <algorithm>
#include <iterator>
#include <list>

template <typename Tkey, typename Tvalue> struct elem_info {
  // struct pt retinerea valorilor pereche de tip cheie-valoare
  Tkey key;
  Tvalue value;
};

template <typename Tkey, typename Tvalue> class Hashtable {
private:
  std::list<struct elem_info<Tkey, Tvalue> > * H; // *H pointer la buckets de tip arraylist
  int HMAX; // nr de bucketuri
  unsigned int (*hash)(Tkey); // pointer la o functie hash

public:
  Hashtable(int hmax, unsigned int (*h)(Tkey)) {
    // TODO: constructor, unde *h e functia de hash
    this->HMAX = hmax;
    this->hash = h;
    H = new std::list<struct elem_info<Tkey, Tvalue> >[HMAX];
  }

  ~Hashtable() {
    // TODO: destructor
    delete[] H;
  }

  void put(Tkey key, Tvalue value) {
    // TODO: put pune o pereche cheie valoare in hashtable
    int hashValue = hash(key) % HMAX;
    struct elem_info<Tkey, Tvalue> newElem;
    newElem.key = key;
    newElem.value = value;

    bool found = false;

    typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
    for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
        if (i->key == key) {
            i->value = value;
            found = true;
        }
    }
    if (!found) {
        H[hashValue].push_back(newElem);
    }
  }

  void remove(Tkey key) {
    // TODO: scoate entry-ul cu cheia key din hashtable
    int hashValue = hash(key) % HMAX;
    typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
    for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
        if(i->key == key) {
            break;
        }
    }
    if (i != H[hashValue].end()) {
        H[hashValue].erase(i);
    }
  }

  Tvalue get(Tkey key) {
    // TODO: intoarce valoarea de la cheia key
    int hashValue = hash(key) % HMAX;
    typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
    for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
        if (i->key == key) {
            return i->value;
        }
    }
    return Tkey();
 }
  bool has_key(Tkey key) {
      int hashValue = hash(key) % HMAX;
      typename std::list<struct elem_info<Tkey, Tvalue> >::iterator i;
      for(i = H[hashValue].begin(); i != H[hashValue].end(); i++) {
          if (i->key == key) {
              return true;
          }
      }
      return false;
  }
};


#endif //__HASHTABLE__Hfndef __HASHTABLE__H
