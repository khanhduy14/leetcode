//
// Created by Duy DA. Kieu Khanh on 14/05/2022.
// https://www.youtube.com/watch?v=_TguKrfVZH4

#include "bits/stdc++.h"

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node *root) {
        Node *now, *tail, *head;

        now = root;
        head = tail = nullptr;
        while (now) {
            if (now->left)
                if (tail) tail = tail->next = now->left;
                else head = tail = now->left;
            if (now->right)
                if (tail) tail = tail->next = now->right;
                else head = tail = now->right;
            if (!(now = now->next)) {
                now = head;
                head = tail = nullptr;
            }
        }
        return root;
    }
};