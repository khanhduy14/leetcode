//
// Created by PC on 3/29/2022.
//

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
    TreeNode* pruneTree(TreeNode* root) {
        if (root->left) root->left = pruneTree(root->left);
        if (root->right) root->right = pruneTree(root->right);
        return root->left == root->right && root->val == 0 ? nullptr : root;
    }
};

TreeNode *newNode(int data) {
    TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
    node->val = data;
    node->left = node->right = nullptr;
    return (node);
}

// Function to insert nodes in level order
TreeNode *insertLevelOrder(vector<int> arr, TreeNode *root,
                           int i, int n) {
    // Base case for recursion
    if (i < n) {
        TreeNode *temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr,
                                      root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr,
                                       root->right, 2 * i + 2, n);
    }
    return root;
}

void inOrder(TreeNode *root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

int main() {
    vector<int> i = {1,NULL,0,0,1};
    TreeNode *root = insertLevelOrder(i, root, 0, 5);

    Solution s;
    TreeNode *r = s.pruneTree(root);
    inOrder(r);
}
