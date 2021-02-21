liste neordonate
typedef int T; 
typedef struct nod {
T val ;  
struct nod *leg ;  
} Nod;


void printL ( Nod* lst) {
while (lst != NULL) {
printf ("%d ",lst->val);
lst=lst->leg;
}
}


// cÃ£utare Ã®ntr-o listÃ£ neordonatÃ£
Nod* findL (Nod* lst, T x) {
while (lst!=NULL && x != lst->val)
lst = lst->leg;
return lst;
// NULL dacÃ£ x negÃ£sit
}
}

// initializare stiva
void initS ( Nod * s) {
s->leg = NULL;
}

// pune in stiva un element
void push (Nod * s, int x) {
Nod * nou = (Nod*)malloc(sizeof(Nod));
nou->val = x; 
nou->leg = s->leg;
s->leg = nou;
}


// scoate din stiva un element
int pop (Nod * s) {
Nod * p; 
int rez;
p = s->leg;  
rez = p->val;  
s->leg = p->leg; 
free (p) ;
return rez;
}

