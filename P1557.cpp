//
// Created by PC on 4/11/2022.
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> g(n, 0);
        for (auto &e: edges) {
            g[e[1]]++;
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!g[i]) res.push_back(i);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> e = {};
    Solution s;
    for (auto &x: s.findSmallestSetOfVertices(6, e)) {
        cout << x << endl;
    }
}