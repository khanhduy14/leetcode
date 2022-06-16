//
// Created by PC on 5/8/2022.
// https://leetcode.com/problems/count-submatrices-with-all-ones/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) dp[i][j] = mat[i][j];
                else dp[i][j] = mat[i][j] == 0 ? 0 : dp[i][j - 1] + 1;
            }
        }

        int r = 0;

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int mi = dp[i][j];
                for (int k = i; k > -1; k--) {
                    mi = min(mi, dp[k][j]);
                    if (mi == 0) {
                        break;
                    }
                    r += mi;
                }
            }
        }
        return r;

    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1, 0, 1},
                               {1, 1, 0},
                               {1, 1, 0}};
    cout << s.numSubmat(mat);
}
