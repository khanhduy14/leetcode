#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int racecar(int target) {
        int dp[target + 1];
        for (int i = 1; i <= target; ++i) {
            dp[i] = INT32_MAX;

            int m = 1, j = 1;
            for (; j < i; j = (1 << ++m) - 1) {
                for (int q = 0, p = 0;  p < j; p = (1 << ++q) - 1) {
                    dp[i] = min(dp[i], m + 1 + q + 1 + dp[i - (j - p)]);
                }
            }

            cout << i << " " << j << endl;

            dp[i] = min(dp[i], m + (i == j ? 0 : 1 + dp[j - i]));
        }
        return dp[target];
    }
};

int main() {
    Solution s;
    cout << s.racecar(3);
}