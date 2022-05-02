//
// Created by PC on 5/2/2022.
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        int lastPos[26] = {};
        bool added[26] = {};
        for (int i = 0; i < s.size(); i++) {
            lastPos[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); i++) {
            if (added[s[i] - 'a']) continue;
            while (!res.empty() && res.back() > s[i] && lastPos[res.back() - 'a'] > i) {
                added[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            added[s[i] - 'a'] = true;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.smallestSubsequence("bcabc");
}
