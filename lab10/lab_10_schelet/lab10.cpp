/* Laborator 10 SD - Treapuri
  * Autor: Andrei Parvu - andrei.parvu@cti.pub.ro
  * Echipa SD, 2014
  *
  * Modificari: Mihai Neacsu - mihai.mneacsu@gmail.com
  * Echipa SD, 2015
  *
  * Modificari: Gabriel Bercaru, 2018
  */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Treap.h"
 #define DEBUG 1
using namespace std;

int main() {
    srand(time(0));

    Treap<int> *treap = new Treap<int>();

    ifstream f("In/date.in");

#ifdef DEBUG
    std::ostream& g0 = std::cout;
    std::ostream& g1 = std::cout;
    std::ostream& g2 = std::cout;
#else
    std::ofstream file0, file1, file2;
    file0.open("Out/Lab10/task1.out");
    file1.open("Out/Lab10/task2.out");
    file2.open("Out/Lab10/task3.out");
    std::ostream& g0 = file0;
    std::ostream& g1 = file1;
    std::ostream& g2 = file2;
#endif

    if (!f) {
        cerr << "Error opening date.in!\n";
        return 0;
    }

    int n, m, x;

    // Verificam functia insert si find
    f >> n;

    for (int i = 1; i <= n; i++) {
        f >> x;

        treap->insert(treap, x, rand() % 1000);
    }

    f >> m;

    for (int i = 1; i <= m; i++) {
        f >> x;

        g0 << "Elementul " << x << (treap->find(x) == true ? " se afla " :
             " nu se afla ") << "in treap\n";
    }

    // Verificam delete si find
    f >> n;

    for (int i = 1; i <= n; i++) {
        f >> x;

        treap->erase(treap, x);
    }

    f >> m;

    for (int i = 1; i <= m; i++) {
        f >> x;

        g1 << "Elementul " << x << (treap->find(x) == true ? " se afla " :
            " nu se afla ") << "in treap\n";
    }

    stringstream ss;
    streambuf *defaultStdout = cout.rdbuf(ss.rdbuf());

    treap->inOrder();
    cout.rdbuf(defaultStdout);
    g2 << ss.str();
    g2 << "\n";

    treap->preOrder();

    f >> n;

    for (int i = 1; i <= n; i++) {
        f >> x;

        g2 << "Al " << x <<"-lea element din treap este " << treap->findK(x) <<
            "\n";
    }

    f.close();

#ifndef DEBUG
    file0.close();
    file1.close();
    file2.close();
#endif

    return 0;
}
