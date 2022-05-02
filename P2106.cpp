//
// Created by Duy DA. Kieu Khanh on 30/04/2022.
// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>> &A, int s, int k) {
        vector<int> dp;
        int i = 0, t = 0;
        dp.push_back(0);
        for (auto &x: A) {
            for (; i < x[0]; ++i) {
                dp.push_back(t);
            }
            i++;
            t = t + x[1];
            dp.push_back(t);
        }
        if (s >= i) {
            if ((s - k) >= i) return 0;
            else return dp[i] - dp[max(0, s - k)];
        }
        int res = 0;
        int x = s > k ? (s - k) : 0;
        for (int j = x; j <= s; ++j) {
            int c = min(k - (s - j) + j + 1, i);
            res = max(res, dp[max(c, s + 1)] - dp[j > 0 ? j : 0]);
        }

        x = min(i - 1, s + k);
        for (int j = s; j <= x; ++j) {
            int c = max(j - (k - (j - s)), 0);
            res = max(res, dp[j + 1] - dp[c]);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> f = {{1,4},{3,7},{4,8},{6,5},{10,3},{12,8},{13,6},{14,5},{16,3},{18,7},{22,7},{24,1},{28,7},{32,3},{34,7},{35,7},{37,7},{40,7}};

    cout << s.maxTotalFruits(f, 41, 10);
}
