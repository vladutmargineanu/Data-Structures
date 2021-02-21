#include <stdio.h>
#include <time.h>

#include "dynvec.h"
#include "simple_realloc_dynvec.h"
#include "ll_dynvec.h"
#include "smart_realloc_dynvec.h"

#define LARGE_NUM_OPERATIONS 1048576
#define SMALL_NUM_OPERATIONS 65536

void dynvec_test(DynamicVector<int> *dv, char *description, int num_operations) {
	int i, x, y, result, tstart = clock(), numop = 0;

	srand(9000);

	for (i = 0; i < num_operations; i++) {
		dv->add_last(rand()); ++numop;
	}

	for (i = 0; i < num_operations; i++) {
		x = rand();
		dv->add_last(x); ++numop;
		result = dv->get_element(num_operations, y); ++numop;
		if (!result || x != y)
			fprintf(stderr, "Error in get_element\n");
		dv->remove_last(); ++numop;
		if (dv->size() != num_operations)
			fprintf(stderr, "Wrong vector size\n");
		++numop;
	}

	srand(9000);
	for (i = 0; i < num_operations; i++) {
		x = rand();
		result = dv->get_element(i, y); ++numop;
		if (!result || x != y)
			fprintf(stderr, "Error in get_element\n");
	}

	for (i = 0; i < num_operations; i++) {
		x = rand();
		result = dv->set_element(i, x); ++numop;
		if (!result)
			fprintf(stderr, "Error in set_element\n");
		result = dv->get_element(i, y); ++numop;
		if (!result || x != y)
			fprintf(stderr, "Error in get_element\n");		
	}
	
	for (i = 0; i < num_operations; i++) {
		dv->remove_last(); ++numop;
	}

	if (dv->size() != 0)
		fprintf(stderr, "Wrong vector size\n");
	++numop;
	
	fprintf(stderr, "%s: number of operations=%d, duration=%.3lf sec\n", description, numop, (double) (clock() - tstart) / CLOCKS_PER_SEC);
}

int main() {
	SimpleReallocDynamicVector<int> simple_rdv;
	dynvec_test(&simple_rdv, "SimpleReallocDynamicVector", LARGE_NUM_OPERATIONS);

	LinkedListDynamicVector<int> lldv;
	dynvec_test(&lldv, "LinkedListDynamicVector", SMALL_NUM_OPERATIONS);
	
	SmartReallocDynamicVector<int> smart_rdv1(2.0, 0.333), smart_rdv2(2.0, 0.25), smart_rdv3(3.0, 0.1), smart_rdv4(2.0, 0.5);
	dynvec_test(&smart_rdv1, "SmartReallocDynamicVector(2.0,0.333)", LARGE_NUM_OPERATIONS);
	dynvec_test(&smart_rdv2, "SmartReallocDynamicVector(2.0,0.25)", LARGE_NUM_OPERATIONS);
	dynvec_test(&smart_rdv3, "SmartReallocDynamicVector(3.0,0.1)", LARGE_NUM_OPERATIONS);
	dynvec_test(&smart_rdv4, "SmartReallocDynamicVector(2.0,0.5)", SMALL_NUM_OPERATIONS);

	return 0;
}
