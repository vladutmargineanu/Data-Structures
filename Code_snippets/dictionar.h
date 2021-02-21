dictionar
#define H 13
typedef struct nod {
char * cuv;
int nr;
struct nod * leg;
} nod;

typedef nod* Map [H];
int hash ( char * s) {
int i,sum=0;
for (i=0;i< strlen(s);i++)
sum=sum+(i+1)*s[i];
return sum % H;
}

// initializare tabel hash
void initD (Map d) {
int i;
for (i=0;i<H;i++)
d[i]=NULL;
}

// afisare dictionar (lista dupa lista)
void printD (Map d) {
int i; 
nod* p;
for (i= 0;i<H;i++) {
p=d[i];
while (p != NULL) {
printf ("%20s %4d\n", p cuv,p nr);
p=p->leg;
}
}
}

// cautare (localizare) cuvÃ¢nt Ã®n dictionar
nod* locD (Map d, char * c) {
nod* p; int k;
k=hash(c);
p=d[k];
while ( p != NULL && strcmp(p->cuv,c))
p=p->leg;
return p;
}

// adauga o pereche cheie-val la dictionar
void putD ( Map d, char * c, int nr) {
nod *p, *pn; int k;
k= hash (c);
if ( (p=locD (d,c)) !=NULL)
p nr=nr;
else {
pn= new nod;
pn->cuv=c; 
pn->nr=nr;
pn->leg= d[k]; 
d[k]=pn;
}
}

// extrage valoarea asociata unei chei date
int getD (Map d, char* c) {
nod *p;
if ( (p=locD (d,c)) != NULL)
return p->nr;

else
return 0;
}

