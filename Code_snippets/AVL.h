functii avl:

int inaltime (nod *p) {
    int c;
    if (p == NULL)
        return -1;
    else {
        c=p->h;
        return c;
    }
}



void adaug (nod *&p, int x) {
    if (p == NULL) {
        p = new nod;
        p->info=x;
        p->s=NULL;
        p->d=NULL;
        p->h=0;
    } else {
        if (x<p->info) {
            adaug(p->s, x);
            if ((inaltime(p->s) - inaltime(p->d)) == 2){
                if (x < p->s->info)
                    p=rss(p);
                else
                    p=rds(p);
            }
        }else if (x >p->info) {
            adaug(p->d, x);
            if ((inaltime(p->d) - inaltime(p->s)) == 2) {
                if (x > p->d->info)
                    p=rsd(p);
                else
                    p=rdd(p);
            }
        }else
            cout<<"Elementul exista deja. \n";
    }
    int m, n, c;
    m=inaltime(p->s);
    n=inaltime(p->d);
    c=max(m,n);
    p->h=c+1;
}



nod *caut_min (nod *p) {
    if (p==NULL) {
        cout<<"Arborele este gol.\n";
        return p;
    } else {
        while (p->s!=NULL)
            p=p->s;
        return p;
    }
}


nod *caut_max (nod *p) {
    if (p==NULL) {
        cout<<"Arborele este gol.\n";
        return p;
    }else {
        while (p->d!=NULL)
            p=p->d;
        return p;
    }
}


void caut_nod (nod *&p, int x) {
    if (p==NULL)
        cout<<"0: Elementul nu a fost gasit.\n";
    else {
        if (x < p->info)
            caut_nod(p->s, x);
        else if (x > p->info)
            caut_nod(p->d, x);
        else cout<<"1: Elementul a fost gasit.\n";
    }
}



void sterg_nod (nod *&p, int x) {
    nod *c;
    if (p == NULL)
        cout<<"Elementul nu a fost gasit.\n";
    else if (x < p->info)
        sterg_nod(p->s, x);
    else if (x > p->info)
        sterg_nod(p->d, x);
    else if ((p->s == NULL) && (p->d == NULL)) {
        c=p;
        free(c);
        p=NULL;
        cout<<"Elementul a fost sters.\n";
    } else if (p->d == NULL) {
        c=p;
        p=p->s;
        free(c);
        cout<<"Elementul a fost sters.\n";
    } else
        p->info = sterg_min(p->d);
}



tnod *find(tnod * r, int x)_
if (r==NULL || r->nr==x)
return r;
else 
if(r->nr > x)
return find(r->s, x)
else
return find (r->d, x)

