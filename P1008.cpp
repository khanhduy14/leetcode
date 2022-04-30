//
// Created by PC on 4/25/2022.
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int i = 0;

    TreeNode *bstFromPreorder(vector<int> &A, int bound = INT_MAX) {
        if (i == A.size() || A[i] > bound) return nullptr;
        TreeNode *root = new TreeNode(A[i++]);
        root->left = bstFromPreorder(A, root->val);
        root->right = bstFromPreorder(A, bound);
        return root;
    }
};