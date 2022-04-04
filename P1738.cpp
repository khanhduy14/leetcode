//
// Created by PC on 4/2/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        priority_queue<int> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = matrix[i][j];
                } else if (i == 0) {
                    dp[i][j] = matrix[i][j] ^ dp[i][j - 1];
                } else if (j == 0) {
                    dp[i][j] = matrix[i][j] ^ dp[i - 1][j];
                } else {
                    dp[i][j] = matrix[i][j] ^ dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1];
                }
                q.push(dp[i][j]);
            }
        }

        while (k-- > 1) {
            q.pop();
        }

        return q.top();
    }
};

int main() {
    vector<vector<int>> a = {{5, 2}, {1, 6}};
    Solution s;
    cout << s.kthLargestValue(a, 2);
}
