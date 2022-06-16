//
// Created by PC on 5/18/2022.
// https://leetcode.com/problems/critical-connections-in-a-network/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        disc = vector<int>(n);
        low = vector<int>(n);
        for (auto conn: connections) {
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return ans;
    }

    void dfs(int curr, int prev) {
        disc[curr] = low[curr] = time++;
        for (int next: edgeMap[curr]) {
            if (disc[next] == 0) {
                dfs(next, curr);
                low[curr] = min(low[curr], low[next]);
            } else if (next != prev)
                low[curr] = min(low[curr], disc[next]);
            if (low[next] > disc[curr])
                ans.push_back({curr, next});
        }
    }

private:
    vector<int> disc{0}, low{0};
    int time = 1;
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> edgeMap;
};

int main() {
    Solution s;
    vector<vector<int>> conn = {{0, 1},
                                {1, 2},
                                {2, 0},
                                {1, 3},
                                {3, 4},
                                {4, 5},
                                {5, 3}};
    for (auto &x: s.criticalConnections(6, conn)) {
        for (int a: x) {
            cout << a << " ";
        }
        cout << endl;
    }
}
