#pragma once
#ifndef TEST_HPP
#define TEST_HPP

#include <array>
#include <string_view>
#include <memory>


constexpr int alpha = 'z' - 'a' + 1;

class Trie {
private:
    template <typename E>
    class TrieNode {
    friend class Trie;

    private:
        E data;
        TrieNode* parent;
        bool hasChildren;
        std::array<std::unique_ptr<TrieNode>, alpha> children;

    public:
        TrieNode() : data{}, parent{nullptr}, hasChildren{false} { for (auto i = 0; i < alpha; ++i) children[i] = nullptr; }
        TrieNode(const E& e) : data{e}, parent{nullptr}, hasChildren{false} { for (auto i = 0; i < alpha; ++i) children[i] = nullptr; }
        ~TrieNode() {  }
    };


public:
    typedef uint32_t uint32;


private:
    std::unique_ptr<TrieNode<char> > root;
    uint32 n;

public:
    Trie();
    ~Trie();

    uint32 size() const;
    bool empty() const;
    void insert(std::string_view);
    bool find(std::string_view);
    void remove(std::string_view);
};


Trie::Trie() : root{std::make_unique<TrieNode<char> >()}, n{1} {  }
Trie::~Trie() { root.reset(); }


typename Trie::uint32 Trie::size() const {
    return n;
}


bool Trie::empty() const {
    return n == 0;
}


void Trie::insert(std::string_view word) {
    TrieNode<char>* itr = root.get();

    for (auto i = 0; i < word.size(); ++i) {
        auto char_index = tolower(word[i]) - 'a';

        if (itr->children[char_index] == nullptr) {
            itr->children[char_index].reset(new TrieNode<char>(word[i]));
            itr->children[char_index]->parent = itr;
            itr->hasChildren = true;
            ++n;
        }

        itr = itr->children[char_index].get();
    }
}


bool Trie::find(std::string_view word) {
    TrieNode<char>* itr = root.get();

    for (auto i = 0; i < word.size(); ++i) {
        auto char_index = tolower(word[i]) - 'a';
 
        if (itr->children[char_index] == nullptr)
            return false;

        itr = itr->children[char_index].get();
    }

    return true;
}


void Trie::remove(std::string_view word) {
    TrieNode<char>* itr = root.get();
    auto char_index = tolower(word[0]) - 'a';
    if (!find(word))
        return;

    for (auto i = 0; i < word.size(); ++i) {
        auto char_index = tolower(word[i]) - 'a';
        itr = itr->children[char_index].get();
    }

    auto i = word.size()-1;
    while (!(itr->hasChildren)) {
        auto char_index = tolower(word[i]) - 'a';
        itr = itr->parent;
        itr->children[char_index].reset();
    }
}

#endif