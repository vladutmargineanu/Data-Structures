#include "sorter.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

template<typename T> class MergeSorter : public Sorter<T> {
	public:
	MergeSorter(T* v, int N, int (*compare)(T,T)) : Sorter<T>(v, N, compare) {
	}

	private:
	T* vaux;

	void merge_sort(int pstart, int pstop) {
		if (pstop - pstart <= 0) {
			return;
		}
		
		int mid = (pstart + pstop) / 2;
		merge_sort(pstart, mid);
		merge_sort(mid + 1, pstop);

		int i = pstart, j = mid + 1, k = pstart - 1;
		
		while (i <= mid && j <= pstop) {
			if (compare(v[i], v[j]) <= 0) {
				k++;
				vaux[k] = v[i];
				i++;
			} else {
				k++;
				vaux[k] = v[j];
				j++;
			}
		}
		
		while (i <= mid) {
			k++;
			vaux[k] = v[i];
			i++;
		}
		
		while (j <= pstop) {
			k++;
			vaux[k] = v[j];
			j++;
		}

		for (i = pstart; i <= pstop; i++) {
			v[i] = vaux[i];
		}
	}

	public:
	void sort() {
		vaux = (T*) malloc(N * sizeof(T));
		merge_sort(0, N - 1);
		free(vaux);
	}
};

int compare_int(int a, int b) {
	return (a - b);
}

int compare_string(char* a, char* b) {
	return strcmp(a, b);
}

int main() {
	int v[] = { 7, 9, 23, 2, 6, 8, 1, 13, 10 };
	
	MergeSorter<int> int_sorter(v, 9, compare_int);
	int_sorter.sort();

	for (int i = 0; i < 9; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");

	char* s[] = { "Maria", "Ion", "Ana", "Gigel", "Vasilica", "Paul" };

	MergeSorter<char*> string_sorter(s, 6, compare_string);
	string_sorter.sort();

	for (int i = 0; i < 6; i++) {
		printf("%s ", s[i]);
	}
	printf("\n");
	
	return 0;
}
