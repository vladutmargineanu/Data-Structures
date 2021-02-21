/**
 * LabSD 5
 * ex1.cpp
 * Purpose: Example code for map usage.
 *
 * @authors Razvan Radoi, Alex Selea
 * @changes Ioana Stefan
 */

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

class Opt {
public:
    int val;
    std::string ceva;

    Opt () {
        val = 0;
        ceva = "";
    }

    bool operator==(const Opt &opt) {
        return val == opt.val;
    }
};

namespace std
{
  template<>
    struct hash<Opt>
    {
      int
      operator()(const Opt &opt) const
      {
        return hash<int>()(opt.val);
      }
    };
}

int main() {
    int n;                            // numarul de elemente din lista
    std::string x;                    // variabila temporara
    std::map <std::string, int> hash; // map-ul (hash-ul) folosit
    std::unordered_map <Opt, int> hash2;

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
