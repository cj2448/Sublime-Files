#include <bits/stdc++.h>
#include "Trie.hpp"

int main() {
	Trie t;
	
	t.insert("dear");
	t.insert("dell");
	t.insert("dog");
	t.insert("doll");
	t.insert("dip");
	t.insert("tell");
	t.insert("till");
	t.insert("tile");
	t.insert("toll");
	t.insert("troll");
	t.insert("trip");

	std::string_view word{"stop"};

	if (t.find(word))
		std::cout << word << " exists in the Trie\n";
	else
		std::cout << word << " does not exist in the Trie\n";

	word = "stop";
	t.remove(word);
	
	if (t.find(word))
		std::cout << word << " exists in the Trie\n";
	else
		std::cout << word << " does not exist in the Trie\n";
}
