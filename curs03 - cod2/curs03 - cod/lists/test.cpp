#include <iostream>
#include <string>
#include "ArrayList.h"
#include "LinkedList.h"
#include <random>

#define N 100000
using namespace std;

int main() {

  /*
   * La ArrayList observam ca dureaza mult adaugarea la sfarsit din cauza
   * realocarilor care se fac cu o dimensiune relativ mica (cate 10 elemente),
   * dar citirea este extrem de rapida
   */
  //ArrayList<float> datastore;

  /*
   * La LinkedList observam ca adaugarea la sfarsit este extrem de rapida,
   * dar citirea de pe pozitii aleatoare dureaza semnificativ mai mult
   */
  LinkedList<float> datastore;

  /* adaugam la sfarsit N elemente */
  for (int i=0;i<N;i++) {
    float random = ((float) rand()) / (float) RAND_MAX;
    datastore.addLast(random);
    if (i%1000==0) cout<<"added "<<i<<" elements"<<endl;
  }

  /* citim N elemente de pe pozitii random */
  for (int i=0;i<N;i++) {
    float pickup = datastore.getElem(rand()%N);
    if (i%1000==0) cout<<"retrieved "<<i<<" elements"<<endl;
  }

}
