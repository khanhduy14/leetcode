//
// Created by PC on 5/8/2022.
// https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        vector<TreeNode *> stk;
        for (int i = 0; i < nums.size(); ++i) {
            TreeNode *cur = new TreeNode(nums[i]);
            while (!stk.empty() && stk.back()->val < nums[i]) {
                cur->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
                stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front();
    }
};