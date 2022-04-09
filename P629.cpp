//
// Created by PC on 4/8/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[1001][1001] = { 1 };
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                if (j - i >= 0) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
                }
            }
        }
        return dp[n][k];
    }

private:
    const int mod = pow(10, 9) + 7;
};

int main() {
    Solution s;
    cout << s.kInversePairs(4, 1);
}
