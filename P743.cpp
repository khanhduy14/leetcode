//
// Created by Duy DA. Kieu Khanh on 14/05/2022.
// https://leetcode.com/problems/network-delay-time/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<vector<int>>> m(n + 1);
        vector<int> distances(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        int r = 0;
        for (auto &v: times) {
            m[v[0]].push_back({v[1], v[2]});
        }

        priority_queue<pair<int, int>> q;
        q.push({0, k});
        distances[k] = 0;
        while (!q.empty()) {
            pair<int, int> f = q.top();
            q.pop();
            if (visited[f.second]) continue;
            visited[f.second] = true;
            for (auto &x: m[f.second]) {
                distances[x[0]] = min(-f.first + x[1], distances[x[0]]);
                q.push({-distances[x[0]], x[0]});
            }
        }

        for (int i = 1; i < n + 1; ++i) {
            if (i == k) continue;
            if (!visited[i]) return -1;
            r = max(r, distances[i]);
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<vector<int>> times = {{4, 2, 76},
                                 {1, 3, 79},
                                 {3, 1, 81},
                                 {4, 3, 30},
                                 {2, 1, 47},
                                 {1, 5, 61},
                                 {1, 4, 99},
                                 {3, 4, 68},
                                 {3, 5, 46},
                                 {4, 1, 6},
                                 {5, 4, 7},
                                 {5, 3, 44},
                                 {4, 5, 19},
                                 {2, 3, 13},
                                 {3, 2, 18},
                                 {1, 2, 0},
                                 {5, 1, 25},
                                 {2, 5, 58},
                                 {2, 4, 77},
                                 {5, 2, 74}};
    cout << s.networkDelayTime(times, 5, 3);
}
