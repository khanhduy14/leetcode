//
// Created by PC on 5/17/2022.
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

#include "bits/stdc++.h"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* orig, TreeNode* clone, TreeNode* targ) {
        return orig == nullptr ? nullptr :
               orig == targ ? clone :
               getTargetCopy(orig->left, clone->left, targ) ?: getTargetCopy(orig->right, clone->right, targ);
    }
};