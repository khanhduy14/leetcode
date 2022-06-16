//
// Created by PC on 5/3/2022.
// https://leetcode.com/problems/maximal-rectangle/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));
        int r = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) dp[i][j] = matrix[i][j] == '1';
                else dp[i][j] = matrix[i][j] == '1' ? dp[i][j - 1] + 1 : 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            stack<int> s;
            for (int j = 0; j < n + 1; ++j) {
                while (!s.empty() && dp[s.top()][i] > dp[j][i]) {
                    int f = s.top();
                    s.pop();
                    int x = s.empty() ? 0 : (s.top() + 1);
                    r = max(r, dp[f][i] * (j - x));
                }
                s.push(j);
            }
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<vector<char>> matrix = {{'1', '0', '1', '1', '0', '1'},
                                   {'1', '1', '1', '1', '1', '1'},
                                   {'0', '1', '1', '0', '1', '1'},
                                   {'1', '1', '1', '0', '1', '0'},
                                   {'0', '1', '1', '1', '1', '1'},
                                   {'1', '1', '0', '1', '1', '1'}};
    cout << s.maximalRectangle(matrix);
}
