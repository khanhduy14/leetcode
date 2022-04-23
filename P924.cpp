//
// Created by PC on 4/17/2022.
// https://leetcode.com/problems/minimize-malware-spread/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> parents;

    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        int n = graph.size();
        for (int i = 0; i < n; ++i) parents.push_back(i);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (graph[i][j]) uni(i, j);
        vector<int> area(n, 0), malware(n, 0);
        for (int i = 0; i < n; ++i) area[find(i)]++;
        for (int i: initial) malware[find(i)]++;
        vector<int> res = {1, 0};
        for (int i: initial)
            res = min(res, {(malware[find(i)] == 1) * (-area[find(i)]), i});
        return res[1];
    }

    int find(int x) {
        if (x != parents[x])
            parents[x] = find(parents[x]);
        return parents[x];
    }

    void uni(int x, int y) {
        parents[find(x)] = find(y);
    }
};

int main() {
    vector<vector<int>> g = {{1, 1, 0},
                             {1, 1, 0},
                             {0, 0, 1}};
    vector<int> i = {0, 1, 2};
    Solution s;
    cout << s.minMalwareSpread(g, i);
}
//1 1 0
//1 1 0
//0 0 1

