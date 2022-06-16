//
// Created by PC on 4/9/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if (grid[0][0] != 0) return -1;
        vector<vector<int>> k = {{0,  1},
                                 {-1,  1},
                                 {-1, 0},
                                 {-1, -1},
                                 {0,  -1},
                                 {1,  -1},
                                 {1,  0},
                                 {1,  1}};
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dp[0][0] = 1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;
            for (vector<int> &t: k) {
                int xn = x + t[0];
                int yn = y + t[1];
                if (xn >= 0 && xn < n && yn >= 0 && yn < n && grid[xn][yn] == 0 && !visited[xn][yn]) {
                    dp[xn][yn] = min(dp[xn][yn], dp[x][y] + 1);
                    q.push({xn, yn});
                }
            }
        }
        return dp[n - 1][n - 1] == INT_MAX ? -1 : dp[n - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> g = {{0, 1, 1, 0, 0, 0},
                             {0, 1, 0, 1, 1, 0},
                             {0, 1, 1, 0, 1, 0},
                             {0, 0, 0, 1, 1, 0},
                             {1, 1, 1, 1, 1, 0},
                             {1, 1, 1, 1, 1, 0}};
    Solution s;
    cout << s.shortestPathBinaryMatrix(g);
}
