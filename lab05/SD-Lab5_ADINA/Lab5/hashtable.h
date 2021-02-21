/**
 * LabSD 5
 * hashtable.h
 * Purpose: Skeleton code for Hashtable.
 *
 * @authors Razvan Radoi, Alex Selea
 * @changes Ioana Stefan
 */

#ifndef __HASHTABLE__H
#define __HASHTABLE__H
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

#define TRESHOLD 0.75

template <typename Tkey, typename Tvalue> struct elem_info {
	Tkey key;
	Tvalue value;

	elem_info(Tkey k, Tvalue v) : key(k), value(v) {}
};

template <typename Tkey, typename Tvalue> class Hashtable {
private:
	std::list<struct elem_info<Tkey, Tvalue> > * H; // pointer to buckets
	int HMAX; // number of buckets
	unsigned int (*hash)(Tkey); // pointer to hash function
	unsigned int size; // number of elements in hashtable

public:
	Hashtable(int hmax, unsigned int (*h)(Tkey)) {
		// TODO 2: initializations, use *h as hash function
		HMAX = hmax;
		hash = h;
		size = 0;

		H = new std::list<struct elem_info<Tkey, Tvalue> >[HMAX];		
	}

	~Hashtable() {
		// TODO 2: free memory
		for (int i = 0; i < HMAX; i++) {
			while (!H[i].empty()) {
				H[i].pop_front();
			}
		}

		delete [] H;
	}

	void put(Tkey key, Tvalue value) {
		// TODO 2
		bool found = false;
		int index = hash(key) % HMAX;
		typename std::list<struct elem_info<Tkey, Tvalue> >::iterator it;

		for (it = H[index].begin(); it != H[index].end(); ++it) {
			if (it->key == key) {
				found = true;
				it->value = value;
				break;
			}
		}

		if (!found) {
			H[index].push_back(elem_info<Tkey, Tvalue>(key, value));
			size++;
		}

		if (this->current_factor() >= TRESHOLD) {
			this->resize();
		}

 	}

	void remove(Tkey key) {
		// TODO 2
		int index = hash(key) % HMAX;
		typename std::list<struct elem_info<Tkey, Tvalue> >::iterator it;

		for (it = H[index].begin(); it != H[index].end(); ++it) {
			if (it->key == key) {
				H[index].erase(it);
				size--;
				return;
			}
		}

	}

	Tvalue get(Tkey key) {
		// TODO 2
		int index = hash(key) % HMAX;
		typename std::list<struct elem_info<Tkey, Tvalue> >::iterator it;

		for (it = H[index].begin(); it != H[index].end(); ++it) {
			if (it->key == key) {
				return it->value;
			}
		}

		return Tvalue();
	}

	bool has_key(Tkey key) {
		// TODO 2
		int index = hash(key) % HMAX;
		typename std::list<struct elem_info<Tkey, Tvalue> >::iterator it;
		
		for (it = H[index].begin(); it != H[index].end(); ++it) {
			if (it->key == key) {
				return true;
			}
		}
		return false;
	}

	void resize() {
		//TODO BONUS
		HMAX *= 2;
		std::list<struct elem_info<Tkey, Tvalue> > * newH;

		newH = new std::list<struct elem_info<Tkey, Tvalue> >[HMAX];

		for (int i = 0; i < HMAX / 2; i++) {
			typename std::list<struct elem_info<Tkey, Tvalue> >::iterator it;

			for (it = H[i].begin(); it != H[i].end(); ++it) {
				int index = hash(it->key) % HMAX;
				newH[index].push_back(elem_info<Tkey, Tvalue>(it->key, it->value));
			}
		}

		delete [] H;
		H = newH;	
	}

	int get_size() {
		return size;
	}

	int get_capacity() {
		return HMAX;
	}

	float current_factor(){
		return (float)(size) / (float)(HMAX);
	}
};

#endif //__HASHTABLE__
