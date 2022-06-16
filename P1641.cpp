//
// Created by PC on 5/11/2022.
// https://leetcode.com/problems/count-sorted-vowel-strings/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6));
        for (int i = 1; i <= n; ++i)
            for (int k = 1; k <= 5; ++k)
                dp[i][k] = dp[i][k - 1] + (i > 1 ? dp[i - 1][k] : 1);
        return dp[n][5];
    }
};

int main() {
    Solution s;
    cout << s.countVowelStrings(32);
}
