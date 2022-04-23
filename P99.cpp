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
    TreeNode *f1 = nullptr;
    TreeNode *f2 = nullptr;
    TreeNode *prev = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        traverse(root);
        cout << f1->val << " " << f2->val << endl;
        swap(f1->val, f2->val);
    }

    void traverse(TreeNode *root) {
        if (root == nullptr) return;

        traverse(root->left);
        if (f1 == nullptr && root->val < prev->val) {
            f1 = prev;
        }
        if (f1 != nullptr && root->val < prev->val) {
            f2 = root;
        }
        prev = root;
        traverse(root->right);
    }
};