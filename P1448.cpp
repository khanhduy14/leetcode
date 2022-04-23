//
// Created by PC on 4/23/2022.
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int r = 0;
    int goodNodes(TreeNode* root) {
        count(root, INT_MIN);
        return r;
    }
private:
    void count(TreeNode *root, int m) {
        if (root == nullptr) return;
        if (root->val >= m) r++;
        count(root->left, max(m, root->val));
        count(root->right, max(m, root->val));
    }
};
