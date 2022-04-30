//
// Created by Duy DA. Kieu Khanh on 30/04/2022.
// https://leetcode.com/problems/evaluate-division/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        unordered_map<string, pair<double, int>> m;
        unordered_map<string, vector<int>> t;
        for (int i = 0; i < values.size(); ++i) {
            t[equations[i][0]].push_back(i);
            t[equations[i][1]].push_back(i);
        }

        int i = 0;

        for (auto &k: t) {
            if (m.count(k.first) != 0) continue;
            queue<string> q;
            q.push(k.first);
            m[k.first] = {1, ++i};
            while (!q.empty()) {
                string f = q.front(); q.pop();
                for (int x: t[f]) {
                    if (equations[x][0] == f && m.count(equations[x][1]) == 0) {
                        m[equations[x][1]] = {m[f].first / values[x], i};
                        q.push(equations[x][1]);
                    } else if (equations[x][1] == f && m.count(equations[x][0]) == 0) {
                        m[equations[x][0]] = {values[x] * m[f].first, i};
                        q.push(equations[x][0]);
                    }
                }
            }
        }

        vector<double> r;
        for (vector<string> &v: queries) {
            if (m.count(v[1]) == 0 || m.count(v[0]) == 0 || m[v[0]].second != m[v[1]].second) r.push_back(-1);
            else {
                r.push_back(m[v[0]].first / m[v[1]].first);
            }
        }

        return r;
    }
};

int main() {
    vector<vector<string>> e = {{"a", "b"},
                                {"c", "d"}};
    vector<vector<string>> q = {{"a", "c"},
                                {"b", "d"},
                                {"b", "a"},
                                {"d", "c"}};
    vector<double> v = {1.0, 1.0};
    Solution s;
    for (double x: s.calcEquation(e, v, q)) {
        cout << x << " ";
    }
}
