#include "sorter.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

template<typename T> class QuickSorter : public Sorter<T> {
	public:
	QuickSorter(T* v, int N, int (*compare)(T,T)) : Sorter<T>(v, N, compare) {
	}

	private:
	T aux_val;

	int alege_pivot(int pstart, int pstop) {
		T vmax = v[pstart];
		int i;
		for (i = pstart + 1; i <= pstop; i++) {
			if (compare(vmax, v[i]) < 0) {
				vmax = v[i];
			}
		}
		
		for (i = pstart; i <= pstop; i++) {
			if (compare(v[i], vmax) < 0) {
				return i;
			}
		}
			
		return -1;
	}
	
	void quick_sort(int pstart, int pstop) {
		if (pstop - pstart <= 0) {
			return;
		}
				
		int pozitie_pivot = alege_pivot(pstart, pstop);
		if (pozitie_pivot < 0) {
			return;
		}

		T pivot = v[pozitie_pivot];
		int i = pstart, j = pstop;
		while (i <= j) {
			if (compare(v[i], pivot) <= 0) {
				i++;
			} else if (compare(v[j], pivot) > 0) {
				j--;
			} else {
				aux_val = v[i];
				v[i] = v[j];
				v[j] = aux_val;
				i++;
				j--;
			}
		}

		if (i <= pstop) {
			quick_sort(pstart, i - 1);
		}
		
		if (i > pstart) {
			quick_sort(i, pstop);
		}
	}

	public:
	void sort() {
		quick_sort(0, N - 1);
	}
};

/*
int compare_int(int a, int b) {
	return (a - b);
}

int compare_string(char* a, char* b) {
	return strcmp(a, b);
}

int main() {
	int v[] = { 7, 9, 23, 2, 6, 8, 1, 13, 10 };
	
	QuickSorter<int> int_sorter(v, 9, compare_int);
	int_sorter.sort();

	for (int i = 0; i < 9; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");

	char* s[] = { "Maria", "Ion", "Ana", "Gigel", "Vasilica", "Paul" };

	QuickSorter<char*> string_sorter(s, 6, compare_string);
	string_sorter.sort();

	for (int i = 0; i < 6; i++) {
		printf("%s ", s[i]);
	}
	printf("\n");
	
	return 0;
}
*/