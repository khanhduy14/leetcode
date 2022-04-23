//
// Created by PC on 4/19/2022.
// https://leetcode.com/problems/recover-binary-search-tree/

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
    int r;
    int sumNumbers(TreeNode *root) {
        traverse(root, 0);
        return r;
    }

    void traverse(TreeNode *root, int s) {
        s = s * 10 + root->val;
        if (root->right == root->left) r += s;
        if (root->right != nullptr) traverse(root->right, s);
        if (root->left != nullptr) traverse(root->left, s);
    }
};