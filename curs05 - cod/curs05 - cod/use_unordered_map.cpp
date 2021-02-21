#include <fstream> // std::cout
#include <unordered_map> // std::map
#include <time.h>
#include <sys/time.h>
#include "dosar.h"

using namespace std;

void index(unordered_map <string,Dosar>& bd) {
	ifstream refugees;
	refugees.open("refugees.csv");
	string buffer;

	getline(refugees, buffer); //header
	while (getline(refugees, buffer)) {
		int firstComma = buffer.find_first_of(',');
		bd[buffer.substr(0,firstComma)] = Dosar(buffer.substr(firstComma+1,buffer.length()-firstComma));
	}
}

int main() {
	
	struct timeval start, end;

	gettimeofday(&start, NULL);
	unordered_map <string,Dosar> bd;
	index(bd);
	gettimeofday(&end, NULL);

	cout << "Timp indexare: " << ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)) << endl;

	gettimeofday(&start, NULL);
	Dosar d = bd["CLEMENTE BROOKS"];
	gettimeofday(&end, NULL);

	cout << "Timp mediu cautare: " << ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)) << endl;

	cout << "Buckets: " << bd.bucket_count() << endl;

	cout << "Load factor: " << bd.load_factor() << endl;

	int collisions = 0;
	for (int i=0; i<bd.bucket_count(); i++) {
		int bucket_size = bd.bucket_size(i);
		if (bucket_size > 1)
			collisions += bucket_size-1;
	}
	cout << "Collisions: " << collisions << endl;

	return 0;
	
}