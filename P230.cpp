//
// Created by PC on 4/18/2022.
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> s;

        while (root != NULL) {
            s.push(root);
            root = root->left;
        }

        while (k--) {
            TreeNode *curr = s.top();
            s.pop();

            if (k == 0) return curr->val;

            TreeNode *right = curr->right;
            while (right != nullptr) {
                s.push(right);
                right = right->left;
            }
        }

        return -1;
    }
};