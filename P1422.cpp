//
// Created by Duy DA. Kieu Khanh on 03/05/2022.
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        vector<vector<int>> v;
        v.push_back({0, 0});
        for (char c: s) {
            if (c == '0') v.push_back({v.back()[0] + 1, v.back()[1]});
            if (c == '1') v.push_back({v.back()[0], v.back()[1]  + 1});
        }

        int m = v.back()[1];
        int r = 0;
        for (int i = 1; i < v.size() - 1; ++i) {
            r = max(r, v[i][0] + m - v[i][1]);
        }

        return r;
    }
};

int main() {
    Solution s;
    cout << s.maxScore("011101");
}
