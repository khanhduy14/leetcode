//
// Created by PC on 4/21/2022.
// https://leetcode.com/problems/binary-search-tree-iterator/

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

class BSTIterator {
    vector<int> arr;
    int i = 0;
public:
    void inorder(TreeNode *&root) {
        if (!root)return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(TreeNode *root) {
        inorder(root);
    }

    int next() {
        int ans = arr[i];
        i++;
        return ans;

    }

    bool hasNext() {

        if (i < arr.size())
            return true;
        return false;
    }
};