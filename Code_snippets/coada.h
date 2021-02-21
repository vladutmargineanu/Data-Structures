coada
#define M 100
typedef struct {
int nel;
T elem [M];
int prim,ultim ;
} Queue ;

// initializare coada
void initQ (Queue & q) { 
q.prim=q.ultim=0; 
q.nel=0;
}

// test coada plina
int fullQ (Queue q) {
return (q.nel==M);
}

// test coada goala
int emptyQ (Queue q) {
return (q.nel==0);
}

// introducere element in coada
void addQ (Queue & q, T x ) {
q.nel++;
q.elem[q.ultim]=x;
q.ultim=(q.ultim+1) % M ;
}

// extrage element dintr-o coada
T delQ (Queue & q) {
T x;
q.nel--;
x=q.elem[q.prim];
q.prim=(q.prim+1) % M ;
return x;
}

