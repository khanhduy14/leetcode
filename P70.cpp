//
// Created by PC on 4/4/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                dp[i] = 1;
                continue;
            }
            if (i == 2) {
                dp[i] = 2;
                continue;
            }
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(4);
}