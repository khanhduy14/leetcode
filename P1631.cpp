//
// Created by PC on 4/28/2022.
// https://leetcode.com/problems/path-with-minimum-effort/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> k = {{-1, 0},
                                 {0,  1},
                                 {1,  0},
                                 {0,  -1}};
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = 0;
        priority_queue<pair<int, vector<int>>> q;
        q.push({0, {0, 0}});
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            if (dp[f.second[0]][f.second[1]] < f.first ) continue;
            if (f.second[0] == n - 1 && f.second[1] == m - 1) return -f.first;
            for (int l = 0; l < 4; ++l) {
                int x = f.second[0] + k[l][0];
                int y = f.second[1] + k[l][1];
                if ((x < n) && (x >= 0) && (y < m) && (y >= 0)) {
                    int t = max(-f.first, abs(heights[f.second[0]][f.second[1]] - heights[x][y]));
                    if (dp[x][y] <= t ) continue;
                    dp[x][y] = t;
                    q.push({-t, {x, y}});
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<vector<int>> h = {{1, 10, 6, 7, 9, 10, 4, 9}};
    cout << s.minimumEffortPath(h);
}
