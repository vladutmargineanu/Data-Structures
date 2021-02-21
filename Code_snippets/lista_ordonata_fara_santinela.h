liste ord fara santinela
//int
intl(nod *& lst)
lst=NULL;

//adaugare x la lista lui x
void insL(nod *& lst, int x){
nod *aux;
if(lst!=NULL && x>lst->val)
intL(lst->leg, x);
else{
aux=lst;
lst=new nod;
lst->val=x;
lst->leg=aux;
}
}


//eliminare din lista
void dell(nod *& lst,int x){
nod *aux;
if(lst!=NULL)
if(x!=lst->val)
dell(lst->leg,x);
else{
aux=lst
lst=lst->leg;
free(aux);
}
}


