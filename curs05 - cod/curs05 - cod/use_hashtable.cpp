#include <fstream> // std::cout
#include <iostream> // std::cout
#include <time.h>
#include <sys/time.h>
#include "sd/hashtable.h"
#include "dosar.h"

#define VMAX 1000

using namespace std;

int badHash(string key) {
    return key.length();
}

int customHash(string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * 31 + key[i]) % VMAX;
    return hkey;
}

void index(Hashtable<string,Dosar>& bd) {
	ifstream refugees;
	refugees.open("refugees.csv");
	string buffer;

	getline(refugees, buffer); //header
	while (getline(refugees, buffer)) {
		int firstComma = buffer.find_first_of(',');
	    bd.put(buffer.substr(0,firstComma), Dosar(buffer.substr(firstComma+1,buffer.length()-firstComma)));
	}
}

int main() {

	struct timeval start, end;

	gettimeofday(&start, NULL);
	Hashtable<string,Dosar> bd = Hashtable<string,Dosar>(VMAX, customHash);
	index(bd);
	gettimeofday(&end, NULL);

	cout << "Timp indexare: " << ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)) << endl;

	gettimeofday(&start, NULL);
	Dosar d = bd.get("CLEMENTE BROOKS");
	gettimeofday(&end, NULL);

	cout << "Timp cautare: " << ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)) << endl;

	cout << "Buckets: " << VMAX << endl;

	cout << "Load factor: " << (double)100000/VMAX << endl;

	cout << "Collisions: " << bd.getCollisions() << endl;

	cout << "Max Collisions: " << bd.getMaxCollisions() << endl;

	return 0;

}
