#pragma once
#ifndef TEST_HPP
#define TEST_HPP

#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <queue>

class ExtendedTrie {
private:
    template <typename E>
    class TrieNode {
    friend class ExtendedTrie;

    private:
        E data;
        TrieNode* parent;
        bool hasChildren;
        std::vector<std::unique_ptr<TrieNode> > children;

    public:
        TrieNode() : data{}, parent{nullptr}, hasChildren{false}, children{} {  }
        TrieNode(const E& e) : data{e}, parent{nullptr}, hasChildren{false}, children{} {  }
        ~TrieNode() {  }
    };


public:
    typedef uint32_t uint32;


private:
    std::unique_ptr<TrieNode<std::string_view> > root;
    uint32 n;

public:
    ExtendedTrie();
    ~ExtendedTrie();

    uint32 size() const;
    bool empty() const;
    void insert(std::string_view);
    bool find(std::string_view) const;
    void remove(std::string_view);
    void print() const;
};


ExtendedTrie::ExtendedTrie() : root{std::make_unique<TrieNode<std::string_view> >()}, n{1} { 
    root->children.resize(25);
    for (auto i = 0; i < 25; ++i) root->children[i] = nullptr;
}

ExtendedTrie::~ExtendedTrie() { root.reset(); }


typename ExtendedTrie::uint32 ExtendedTrie::size() const {
    return n;
}


bool ExtendedTrie::empty() const {
    return n == 1;
}


void ExtendedTrie::insert(std::string_view word) {
    TrieNode<std::string_view>* itr = root.get();
    auto char_index = tolower(word[0]) - 'a';

    if (itr->children[char_index] == nullptr) {
        itr->children[char_index].reset(new TrieNode<std::string_view>(word));
        itr->hasChildren = true;
        itr->children[char_index]->parent = itr;
        ++n;
        return;
    }

    itr = itr->children[char_index].get();
    auto ch_ptr = 0;
    std::string_view temp{word};
    do {
        uint32 sub;
        auto min = std::min(temp.size(), itr->data.size());
        for (sub = 0; sub < min; ++sub) {
            if (temp[sub] != itr->data[sub])
                break;
            ++ch_ptr;
        }

        if (word == (itr->data.substr(0, sub))/* or ch_ptr == word.size()*/) { // temp is a complete substring of current node
            itr->children.push_back(std::unique_ptr<TrieNode<std::string_view> >(new TrieNode<std::string_view>(itr->data.substr(sub, itr->data.size() - sub))));
            itr->hasChildren = true;
            itr->children.back()->parent = itr;
            itr->data = temp.substr(0, sub);
            ++n;
            return;
        }

        else if (/*sub > 0 and */sub < min) { // temp contains chars of current not but is not a complete substring
            auto new_data_size = itr->data.size() - sub;
            std::vector<std::string_view> shift;
            for (auto i = 0; i < itr->children.size(); ++i)
                if (!(itr->children[i]->hasChildren))
                    shift.push_back(itr->children[i]->data);


            if (shift.size() == itr->children.size()) {
                itr->children.clear();
            
                itr->children.push_back(std::unique_ptr<TrieNode<std::string_view> >(new TrieNode<std::string_view>(itr->data.substr(sub, itr->data.size() - sub))));
                itr->hasChildren = true;
                itr->children.back()->parent = itr;

                TrieNode<std::string_view>* current = itr->children.front().get();
                for (auto i = 0; i < shift.size(); ++i) {
                    current->children.push_back(std::unique_ptr<TrieNode<std::string_view> >(new TrieNode<std::string_view>(shift[i])));
                    current->hasChildren = true;
                    current->children.back()->parent = current;
                }

                itr->children.push_back(std::unique_ptr<TrieNode<std::string_view> >(new TrieNode<std::string_view>(temp.substr(sub, temp.size() - sub))));
                itr->hasChildren = true;
                itr->children.back()->parent = itr;
                ++n;

                itr->data = temp.substr(0, sub);
                return;
            }
        }

        itr->children.push_back(std::unique_ptr<TrieNode<std::string_view> >(new TrieNode<std::string_view>(itr->data.substr(sub, itr->data.size() - sub))));
        itr->hasChildren = true;
        itr->children.back()->parent = itr;

        itr->children.push_back(std::unique_ptr<TrieNode<std::string_view> >(new TrieNode<std::string_view>(temp.substr(sub, temp.size() - sub))));
        itr->hasChildren = true;
        itr->children.back()->parent = itr;
        ++n;

        // update itr and temp here
        // temp = temp.substr(sub, temp.size() - sub);
    } while (/*ch_ptr < word.size()*/false);
}


// bool ExtendedTrie::find(std::string_view word) const {
//     TrieNode<char>* itr = root.get();

//     for (auto i = 0; i < word.size(); ++i) {
//         auto char_index = tolower(word[i]) - 'a';
 
//         if (itr->children[char_index] == nullptr)
//             return false;

//         itr = itr->children[char_index].get();
//     }

//     return true;
// }


// void ExtendedTrie::remove(std::string_view word) {
//     TrieNode<char>* itr = root.get();
//     auto char_index = tolower(word[0]) - 'a';
//     if (!find(word))
//         return;

//     for (auto i = 0; i < word.size(); ++i) {
//         auto char_index = tolower(word[i]) - 'a';
//         itr = itr->children[char_index].get();
//     }

//     auto i = word.size()-1;
//     while (!(itr->hasChildren)) {
//         auto char_index = tolower(word[i]) - 'a';
//         itr = itr->parent;
//         itr->children[char_index].reset();
//     }
// }

void ExtendedTrie::print() const {
    TrieNode<std::string_view>* itr = root.get();

    if (!itr->hasChildren)
        return;

    std::queue<TrieNode<std::string_view>* > q;
    q.push(itr);
    while (!q.empty()) {
        auto n = q.size();

        while (n > 0) {
            TrieNode<std::string_view>* temp = q.front();
            q.pop();
            std::cout << temp->data << " ";

            for (auto i = 0; i < temp->children.size(); ++i)
                if (temp->children[i] != nullptr)
                    q.push(temp->children[i].get());
                
            --n;
        }

        std::cout << '\n';
    }
}


#endif