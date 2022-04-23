//
// Created by PC on 4/18/2022.
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> v;
        if (!root) return v;
        queue<TreeNode *> q;
        q.push(root);
        int f = 0;
        while (!q.empty()) {
            int k = q.size();
            vector<int> tmp;
            while (k--) {
                TreeNode *tree = q.front();
                q.pop();
                if (tree->left) q.push(tree->left);
                if (tree->right) q.push(tree->right);
                tmp.push_back(tree->val);
            }
            if (f) {
                reverse(tmp.begin(), tmp.end());
                f = 0;
            } else
                f = 1;
            v.push_back(tmp);
        }
        return v;
    }
};

// Using recursion
class Solution_Rec {
public:
    vector<vector<int>> r;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        print(root, 0);
        for (int i = 0; i < r.size(); ++i) {
            if (i % 2 == 1) reverse(r[i].begin(), r[i].end());
        }
        return r;
    }

    void print(TreeNode* root, int k) {
        if (root == nullptr) return;
        if (r.size() <= k) r.push_back({root->val});
        else r[k].push_back(root->val);

        print(root->left, k + 1);
        print(root->right, k + 1);
    }
};