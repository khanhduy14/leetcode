//
// Created by Duy DA. Kieu Khanh on 01/05/2022.
// https://leetcode.com/problems/tallest-billboard/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int> &rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int x: rods) {
            unordered_map<int, int> cur(dp);
            for (auto it: cur) {
                int d = it.first;
                dp[d + x] = max(dp[d + x], cur[d]);
                dp[abs(d - x)] = max(dp[abs(d - x)], cur[d] + min(d, x));
            }
        }
        return dp[0];
    }
};

int main() {
    Solution s;
    vector<int> rods = {1, 2, 3, 6};
    cout << s.tallestBillboard(rods);
}
