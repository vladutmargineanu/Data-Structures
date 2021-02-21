#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "global_rebuilding_bst.h"
#include "logical_remove_bst.h"
#include "scapegoat_tree.h"
#include "linked_list.h"

#define NUM_ELEMS 10000

template<typename TreeNodeType> void test_bst(BinarySearchTree<int, TreeNodeType > *bst, char* msg, int worst_case) {
	fprintf(stderr, "\n\n");
	srand(1000);
	LinkedList<int> ll(compare_int);

	int i, tstart = clock();
	for (i = 0; i < NUM_ELEMS; i++) {
		int k;
		if (worst_case)
			k = 2 * i + 1;
		else
			k = rand() % NUM_ELEMS;
		bst->insert_info(k);
		ll.addLast(k);
	}
	fprintf(stderr, "%s: Dupa insert-uri: ", msg);
	bst->print_statistics();

	struct list_elem<int> *p = ll.plast;
	for (i = NUM_ELEMS - 1; i >= 0; i--) {
		if (bst->find_info(p->info) == NULL) {
			fprintf(stderr, "EROARE! Elementul %d nu a fost gasit in arbore\n", 2 * i + 1);
		}
		p = p->prev;
	}

	p = ll.pfirst;
	for (i = 0; i < NUM_ELEMS; i++) {
		bst->remove_info(p->info);
		p = p->next;
	}
	fprintf(stderr, "%s: Dupa remove-uri: ", msg);
	bst->print_statistics();

	fprintf(stderr, "%s: Durata=%.3lf sec\n", msg, (double) (clock() - tstart) / CLOCKS_PER_SEC);
}

int main() {
	BinarySearchTree<int, BSTNode<int> > bst(compare_int);
	test_bst<BSTNode<int> >(&bst, "Arbore binar de cautare standard (random)", 0);

	BinarySearchTree<int, BSTNode<int> > bst2(compare_int);
	test_bst<BSTNode<int> >(&bst2, "Arbore binar de cautare standard (worst case)", 1);

	BinarySearchTree<int, LogicalRemoveBSTNode<int> > lrbst(compare_int);
	test_bst<LogicalRemoveBSTNode<int> >(&lrbst, "Arbore binar de cautare cu stergere logica (random)", 0);

	BinarySearchTree<int, LogicalRemoveBSTNode<int> > lrbst2(compare_int);
	test_bst<LogicalRemoveBSTNode<int> >(&lrbst2, "Arbore binar de cautare cu stergere logica (worst case)", 1);

	GlobalRebuildingBinarySearchTree<int, BSTNode<int> > grbst(compare_int);
	test_bst<BSTNode<int> >(&grbst, "Arbore binar de cautare cu refacere totala (random)", 0);

	GlobalRebuildingBinarySearchTree<int, BSTNode<int> > grbst2(compare_int);
	test_bst<BSTNode<int> >(&grbst2, "Arbore binar de cautare cu refacere totala (worst case)", 1);

	GlobalRebuildingBinarySearchTree<int, LogicalRemoveBSTNode<int> > grlrbst(compare_int);
	test_bst<LogicalRemoveBSTNode<int> >(&grlrbst, "Arbore binar de cautare cu stergere logica si refacere totala (random)", 0);

	GlobalRebuildingBinarySearchTree<int, LogicalRemoveBSTNode<int> > grlrbst2(compare_int);
	test_bst<LogicalRemoveBSTNode<int> >(&grlrbst2, "Arbore binar de cautare cu stergere logica si refacere totala (worst case)", 1);

	ScapegoatTree<int, ScapegoatTreeNode<int> > sgt(compare_int);
	test_bst<ScapegoatTreeNode<int> >(&sgt, "Scapegoat tree (random)", 0);

	ScapegoatTree<int, ScapegoatTreeNode<int> > sgt2(compare_int);
	test_bst<ScapegoatTreeNode<int> >(&sgt2, "Scapegoat tree (worst case)", 1);
	
	return 0;
}
