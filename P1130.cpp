//
// Created by PC on 5/2/2022.
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int> &A) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a: A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> arr = {15, 13, 5, 3, 15};
    cout << s.mctFromLeafValues(arr);
}
