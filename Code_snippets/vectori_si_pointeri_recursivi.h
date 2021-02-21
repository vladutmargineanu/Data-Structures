vectori recursivi
#define M 100 

typedef struct { 
Ptr v[M]; 
int dim; 
} Vector; 

// initializare vector
void initV (Vector & a) { 
a.dim = 0;
}


 //afisare date de la adresele continute in vector
void printV ( Vector a, fprnt print ) {
int i;
for(i=0;i<a.dim;i++)
print (a.v[i]);
printf ("\n");
}


// adaugare la sfirsitul unui vector de pointeri
void addV ( Vector & a, Ptr p) {
assert (a.dim < M);
a.v [a.dim ++] = p;
}

 
// cautare in vector de pointeri
int findV ( Vector v, Ptr p, fcmp cmp) {
int i;
for (i=0;i<v.dim;i++)
if ( cmp (p,v.v[i]) == 0)
return i; 
return -1; 
}

