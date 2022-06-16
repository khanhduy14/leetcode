//
// Created by PC on 5/15/2022.
// https://leetcode.com/problems/deepest-leaves-sum/

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
    int deepestLeavesSum(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int max_leaf = 1;
        int sum = 0;
        while (!s.empty()) {
            pair f = s.top();
            s.pop();
            if (f.second > max_leaf) {
                sum = 0;
                max_leaf = f.second;
            }
            if (f.first->left == f.first->right && f.second == max_leaf) {
                sum += f.first->val;
                continue;
            }
            if (f.first->left != nullptr) {
                s.push({f.first->left, f.second + 1});
            }
            if (f.first->right != nullptr) {
                s.push({f.first->right, f.second + 1});
            }
        }

        return sum;
    }
};
