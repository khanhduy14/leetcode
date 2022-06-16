//
// Created by PC on 5/19/2022.
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int dp[200][200]{};
    int maxPath, n, m;

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        maxPath = 0, n = size(matrix), m = size(matrix[0]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                maxPath = max(maxPath, solve(matrix, i, j, -1));
        return maxPath;
    }

    int solve(vector<vector<int>> &mat, int i, int j, int prev) {
        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
        if (dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 + max({solve(mat, i + 1, j, mat[i][j]),
                                   solve(mat, i - 1, j, mat[i][j]),
                                   solve(mat, i, j + 1, mat[i][j]),
                                   solve(mat, i, j - 1, mat[i][j])});
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{9, 9, 4},
                                  {6, 6, 8},
                                  {2, 1, 1}};
    cout << s.longestIncreasingPath(matrix)
}
