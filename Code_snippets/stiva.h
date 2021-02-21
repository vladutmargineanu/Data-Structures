stiva
#define M 100
typedef struct {
T st[M];
int sp;
} Stack;

//initializare
void initS ( Nod * s) {
s->leg = NULL;
}


void push (Nod * s, int x) {
Nod * nou = (Nod*)malloc(sizeof(Nod));
nou->val = x; 
nou->leg = s->leg;
s->leg = nou;
}


// scoate din stiva un element
int pop (Nod * s) {
Nod * p; int rez;
p = s->leg;   
rez = p->val;  
s->leg = p->leg;  
free (p) ;
return rez;

