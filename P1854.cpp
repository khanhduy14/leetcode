//
// Created by PC on 4/17/2022.
// https://leetcode.com/problems/maximum-population-year/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>> &logs) {
        unordered_map<int, int> m;
        sort(logs.begin(), logs.end(), greater<>());
        for (int i = 0; i < logs.size(); ++i) {
            if (i > 0 && logs[i][0] == logs[i - 1][0]) continue;
            m[logs[i][0]]++;
            for (int j = i + 1; j < logs.size(); ++j) {
                if (logs[i][0] < logs[j][1]) m[logs[i][0]]++;
            }
        }

        int t = 0, r = INT_MAX;
        for (auto &x: m) {
            if (x.second >= t) {
                r = x.second == t ? min(r, x.first) : x.first;
                t = x.second;
            }
        }

        return r;
    }
};

int main() {
    vector<vector<int>> logs = {{1966, 1968},
                                {1954, 2030},
                                {1966, 1994},
                                {2030, 2044},
                                {1988, 2036},
                                {1977, 2050},
                                {2036, 2046},
                                {1989, 2048},
                                {2049, 2050},
                                {2008, 2019},
                                {2022, 2031},
                                {1970, 2024},
                                {1957, 1996},
                                {1991, 2034},
                                {1956, 1996},
                                {1959, 1969},
                                {2021, 2050}};
    Solution s;
    cout << s.maximumPopulation(logs);
}
