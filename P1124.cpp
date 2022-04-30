//
// Created by PC on 4/26/2022.
// https://leetcode.com/problems/longest-well-performing-interval/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestWPI(vector<int> &hours) {
        int res = 0, score = 0, n = hours.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < n; ++i) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                res = i + 1;
            } else {
                if (seen.find(score) == seen.end())
                    seen[score] = i;
                if (seen.find(score - 1) != seen.end())
                    res = max(res, i - seen[score - 1]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> h = {10, 7, 8, 7, 10};
    cout << s.longestWPI(h);
}

