//
// Created by PC on 4/16/2022.
// https://leetcode.com/problems/convert-bst-to-greater-tree/

#include <bits/stdc++.h>

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
    int m = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return root;
        if (root->right != nullptr) {
            convertBST(root->right);
        }
        root->val += m;
        m = root->val;


        if (root->left != nullptr) {
            convertBST(root->left);
        }
        return root;
    }
};
