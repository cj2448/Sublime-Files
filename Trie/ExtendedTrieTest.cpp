#include <bits/stdc++.h>
#include "ExtendedTrie.hpp"

int main() {
    ExtendedTrie t;
    
    // t.insert("apple");
    // t.insert("app");
    // t.insert("apt");
    // t.insert("appeal");
    // t.insert("appreciate");
    // t.insert("aptitude");
    // t.insert("at");

    t.insert("apple"); 
    t.insert("app");
    t.insert("appreciate");
    t.insert("appeal");
    t.insert("apt");
    t.insert("at");
    // t.insert("aptitude");

    t.print();

    // std::string_view word{"stop"};

    // if (t.find(word))
    //     std::cout << word << " exists in the ExtendedTrie\n";
    // else
    //     std::cout << word << " does not exist in the ExtendedTrie\n";

    // word = "stop";
    // t.remove(word);
    
    // if (t.find(word))
    //     std::cout << word << " exists in the ExtendedTrie\n";
    // else
    //     std::cout << word << " does not exist in the ExtendedTrie\n";
}
