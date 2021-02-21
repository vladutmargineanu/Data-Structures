#include "Trie.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#define DEBUG

int main() {
	Trie<int> *trie = new Trie<int>(ALPHABET_SIZE);
	std::vector<std::string> words;

#ifdef DEBUG
    std::ostream& out_search = std::cout;
    std::ostream& out_remove = std::cout;
    std::ostream& out_bonus = std::cout;
#else
    std::ofstream file_search, file_remove, file_bonus;
    file_search.open("Out/Lab11/task1.out");
    file_remove.open("Out/Lab11/task2.out");
    file_bonus.open("Out/Lab11/bonus1.out");
    std::ostream& out_search = file_search;
    std::ostream& out_remove = file_remove;
    std::ostream& out_bonus = file_bonus;
#endif

	std::string s;
	s = "arta";
	trie -> insert(s, 1);
	s = "artilerie";
	trie -> insert(s, 2);
	s = "artist";
	trie -> insert(s, 3);
	s = "artistic";
	trie -> insert(s, 4);
	s = "arma";
	trie -> insert(s, 5);
	s = "pusca";
	trie -> insert(s, 6);
	
	int val;
	if (!trie -> search(s, val)) {
		out_search << s << " should be in Trie\n";
	}
	out_search << "Value of " << s << " : " << val << std::endl;
	s = "artistic";
	if (!trie -> search(s, val)) {
		out_search << s << " should be in Trie\n";
	}
	out_search << "Value of " << s << " : " << val << std::endl;
	s = "artist";
	if (!trie -> search(s, val)) {
		out_search << s << " should be in Trie\n";
	}
	out_search << "Value of " << s << " : " << val << std::endl;
	s = "artilerie";
	if (!trie -> search(s, val)) {
		out_search << s << " should be in Trie\n";
	}
	out_search << "Value of " << s << " : " << val << std::endl;
	s = "arma";
	if (!trie -> search(s, val)) {
		out_search << s << " should be in Trie\n";
	}
	out_search << "Value of " << s << " : " << val << std::endl;
	s = "arta";
	if (!trie -> search(s, val)) {
		out_search << s << " should be in Trie\n";
	}
	out_search << "Value of " << s << " : " << val << std::endl;
	s = "artis";
	if (trie -> search(s, val)) {
		out_search << s << " should not be in Trie\n";
	}
	s = "pusca";
	trie -> remove(s);
	if (trie -> search(s, val)) {
		out_remove << s << " should not be in Trie after removal\n";
	}
	s = "artilerie";
	trie -> remove(s);
	if (trie -> search(s, val)) {
		out_remove << s << " should not be in Trie after removal\n";
	}
	s = "arta";
	if (!trie -> search(s, val)) {
		out_remove << s << " should still be in Trie\n";
	}
	s = "artist";
	trie -> remove(s);
	if (trie -> search(s, val)) {
		out_remove << s << " should not be in Trie after removal\n";
	}
	s = "artistic";
	if (!trie -> search(s, val)) {
		out_remove << s << " should still be in Trie\n";
	}
	s = "artist";
	trie -> insert(s, 3);
	s = "artilerie";
	trie -> insert(s, 3);
	s = "pusca";
	trie -> insert(s, 3);
	s = "";
	out_bonus << trie->numWordsWithPrefix(s) << std::endl;
	s = "a";
	out_bonus << trie->numWordsWithPrefix(s) << std::endl;
	s = "art";
	out_bonus << trie->numWordsWithPrefix(s) << std::endl;
	s = "arti";
	out_bonus << trie->numWordsWithPrefix(s) << std::endl;
	s = "articulatie";
	out_bonus << trie->numWordsWithPrefix(s) << std::endl;
	
#ifndef DEBUG
    file_search.close();
    file_remove.close();
    file_bonus.close();
#endif

	return 0;
}
