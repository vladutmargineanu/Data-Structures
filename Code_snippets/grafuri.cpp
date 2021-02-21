grafuri
#include <iostream>
#include <stdlib.h>
#define M 31
using namespace std;

struct nod {
    int val;
    nod *leg;
};

struct graf {
    int n;
    nod *a[M];
};

void init(graf &g, int n) {
    g.n = n;
    for ( int i = 1; i <= n; i++ )
        g.a[i] = NULL;
}

int find(nod *lst, int v) {
    nod *p = lst;
    while ( p != NULL ) {
        if ( p->val == v )
            return 1;
        p = p->leg;
    }
    return 0;
}

void add(graf &g, int x, int y) {
    nod *nou1;
    nod *nou2;
    nod *p;

    p = g.a[x];
    if ( !find(p, y) ) {
        nou1 = new nod;
        nou1->val = y;
        if ( p == NULL ) {
            nou1->leg = NULL;
            g.a[x] = nou1;
        }
        else {
            while ( p->leg != NULL &&  y > p->leg->val )
                p = p->leg;
            if ( y < g.a[x]->val ) {
                nou1->leg = g.a[x];
                g.a[x] = nou1;
            }
            else {
                nou1->leg = p->leg;
                p->leg = nou1;
            }
        }
    }
    p = g.a[y];
    if ( !find(p, x) ) {
        nou2 = new nod;
        nou2->val = x;
        if ( p == NULL ) {
            nou2->leg = NULL;
            g.a[y] = nou2;
        }
        else {
            while ( p->leg != NULL &&  x > p->leg->val )
                p = p->leg;
            if ( x < g.a[y]->val ) {
                nou2->leg = g.a[y];
                g.a[y] = nou2;
            }
            else {
                nou2->leg = p->leg;
                p->leg = nou2;
            }
        }
    }
}
                
void build(graf &g, int m, int v[], int w[]) {
    for ( int i = 0; i < m; i++ )
        add(g, v[i], w[i]);
}

void del(graf &g, int v) {
    g.a[v] = NULL;
    nod *p, *q;
    for ( int i = 1; i <= g.n; i++ ) {
        if ( i == v )
            continue;
        p = g.a[i];
        if ( p != NULL && p->leg == NULL && p->val == v )
            g.a[i] = NULL;
        if ( g.a[i] != NULL && g.a[i]->val == v ) {
            g.a[i] = g.a[i]->leg;
            p = p->leg;
        }

        while ( p != NULL && p->leg != NULL ) {
            if ( p->leg->val == v ) {
                q = p->leg;
                p->leg = p->leg->leg;
                free(q);
            }
            p = p->leg;
        }
    }
}

int grad(graf g, int v) {
    nod *p = g.a[v];
    int nr = 0;
    while ( p != NULL ) {
        nr++;
        p = p->leg;
    }
    return nr;
}

void show(graf g) {
    nod *p;
    for ( int i = 1; i <= g.n; i++ ) {
        cout<<i<<": ";
        p = g.a[i];
        while ( p != NULL ) {
            cout<<p->val<<" ";
            p = p->leg;
        }
        cout<<endl;
    }
}

int maxgrad(graf g) {
   int n = 1;
   int max = grad(g, 1);
   for ( int i = 2; i <= g.n; i++ ) {
       if ( max < grad(g, i) ) {
           max = grad(g, i);
           n = i;
       }
   }
   return n;
}

int empty(graf g) {
    for ( int i = 1; i <= g.n; i++ ) {
        if ( g.a[i] != NULL )
            return 0;
    }
    return 1;
}

void vcover(graf g) {
    int v;
    while ( !empty(g) ) {
        v = maxgrad(g);
        cout<<v<<" ";
        del(g, v);
    }
    cout << endl;
}

int main() {
    graf g;
    init(g, 9);
    int v[] = {1, 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 8};
    int w[] = {2, 4, 5, 3, 6, 4 ,7, 8, 9 ,9 ,9, 9};
    build(g, 12, v, w);
    show(g);
    vcover(g);
    //del(g, 4);
    return 0;
}

