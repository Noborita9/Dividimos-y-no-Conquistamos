#include <bits/stdc++.h>

using namespace std;

struct TrieNodeStruct {
    TrieNodeStruct* children[26];
    bool isEndOfWord;
    
    TrieNodeStruct() {
        isEndOfWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

struct TrieStruct {
    TrieNodeStruct* root;
    
    TrieStruct() {
        root = new TrieNodeStruct();
    }
    
    void insert(string word) {
        TrieNodeStruct* current = root;
        for(char c : word) {
            int index = c - 'a';
            if(current->children[index] == nullptr) {
                current->children[index] = new TrieNodeStruct();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNodeStruct* current = root;
        for(char c : word) {
            int index = c - 'a';
            if(current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }

    bool startsWithDirect(string prefix) {
        TrieNodeStruct* current = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return true;  
    }
};
