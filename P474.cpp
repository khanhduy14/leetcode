//
// Created by PC on 5/23/2022.
// https://leetcode.com/problems/ones-and-zeroes/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string s: strs) {
            int a = 0, b = 0;
            for (char c: s) {
                if (c == '0') a++;
                else b++;
            }
            for (int i = m; i >= a; --i) {
                for (int j = n; j >= b; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - a][j - b] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution s;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    cout << s.findMaxForm(strs, 5, 3);
}
