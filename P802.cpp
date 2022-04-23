//
// Created by PC on 4/19/2022.
// https://leetcode.com/problems/find-eventual-safe-states/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<bool> dp(n, false);
        vector<int> visited(n, 0);

        for (int i = 0; i < n; ++i) {
            topologicalSort(graph, visited, dp, i);
        }

        vector<int> r;
        for (int i = 0; i < n; ++i) {
            if (dp[i]) r.push_back(i);
        }

        return r;
    }
private:
    bool topologicalSort(vector<vector<int>> &graph, vector<int> &visited, vector<bool> &dp, int v) {
        if (visited[v] == 2) return dp[v];

        if (visited[v] == 1) {
            dp[v] = false;
            visited[v] = 2;
            return dp[v];
        }

        if (graph[v].empty()) {
            dp[v] = true;
            visited[v] = 2;
            return dp[v];
        }
        visited[v] = 1;
        bool r = true;
        for (auto &x: graph[v]) {
            r = r && topologicalSort(graph, visited, dp, x);
        }
        visited[v] = 2;
        dp[v] = r;
        return r;
    }
};

int main() {
    vector<vector<int>> g = {{1, 2},
                             {2, 3},
                             {5},
                             {0},
                             {5},
                             {},
                             {}};
    Solution s;
    for (auto &x: s.eventualSafeNodes(g)) {
        cout << x << endl;
    }
}