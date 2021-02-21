#include <iostream> // std::cout
#include <map>      // std::map

int main() {
    int n;                            // numarul de elemente din lista
    std::string x;                    // variabila temporara
    std::map <std::string, int> hash; // map-ul (hash-ul) folosit

    // citire elemente si adaugare in stiva
    std::cout << "n = ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        // citeste un alt element
        std::cout << "x = ";
        std::cin >> x;

        // adauga o aparitie a lui x
        ++hash[ x ];

        // afisare statistici
        std::cout << x << " apare de " << hash[x] << " ori; hash size = " << hash.size() << "\n";
    }

    // parcurgerea elementelor din hash
    std::cout << "Stare finala hash\n";
    std::cout << "hash size = " << hash.size() << '\n';

    for (std::map <std::string, int> :: iterator it = hash.begin(); it != hash.end(); ++it) {
        // extrag key si value
        std::string key = it->first;
        int value = it->second;

        // afisez de cate ori a fost intalnit key
        std::cout << key  << " apare de " << value << " ori\n";
    }

    std::cout << "Golesc hash\n";
    hash.clear();
    std::cout << (hash.empty() ? "Hash gol" : "Hash contine elemente") << "\n";

    return 0;
}
