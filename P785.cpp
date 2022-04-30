//
// Created by PC on 4/29/2022.
// https://leetcode.com/problems/is-graph-bipartite/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, -1);
        vector<bool> vis(n, false);
        for (int i = 0; i < graph.size(); ++i) {
            if (vis[i]) continue;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int f = q.front(); q.pop();
                if (vis[f]) continue;
                vis[f] = true;
                if (dp[f] == -1) dp[f] = 0;
                for (int x: graph[f]) {
                    if (vis[x]) continue;
                    if (dp[x] == -1) dp[x] = !dp[f];
                    else if (dp[x] == dp[f]) return false;
                    q.push(x);
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> g = {{1}, {0, 3}, {3}, {1, 2}};
    cout << s.isBipartite(g);
}
