//
// Created by PC on 4/13/2022.
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <bits/stdc++.h>

using namespace std;

class WordDictionary {
public:
    struct TrieNode {
        TrieNode *children[26];
        bool isEndOfWord;
    };

    TrieNode *root = getNode();


    TrieNode *getNode() {
        auto *pNode = new TrieNode;

        pNode->isEndOfWord = false;

        for (auto &i: pNode->children)
            i = nullptr;

        return pNode;
    }

    WordDictionary() {

    }

    void addWord(string word) {
        TrieNode *pCrawl = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(string word) {
        return searchX(word, 0, root);
    }

    bool searchX(string word, int i, TrieNode *pCrawl) {
        for (; i < word.length(); i++) {
            if (word[i] == '.') {
                for (auto x: pCrawl->children) {
                    if (x && searchX(word, i + 1, x)) return true;
                }
                return false;
            }
            int index = word[i] - 'a';
            cout << word[i] << endl;
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl->isEndOfWord);
    }
};
