// initializare lista cu santinela
void initL (List & lst) {
lst=(Nod*)malloc(sizeof(Nod));
lst->leg=NULL;
}


// afisare lista cu santinela
void printL ( List lst) {
lst=lst->leg;
while (lst != NULL) {
printf("%d ", lst->val);
lst=lst->leg;
}
}


// inserare in lista ordonata cu santinela
void insL (List lst, int x) {
Nod *p=lst, *nou ;
nou= (Nod*)malloc(sizeof(Nod));
nou->val=x;
while( p->leg != NULL && x > p->leg->val )
p=p->leg;
nou->leg=p->leg; p->leg=nou; // nou dupa p
}


// eliminare din lista ordonata cu santinela
void delL (List lst, int x) {
Nod*p=lst; Nod*q;
while ( p->leg !=NULL && x > p->leg->val)
p=p->leg;
if (p->leg ==NULL || x !=p->leg->val) return;
q=p->leg;
p leg=p->leg->leg;
free(q);
}

