//
// Created by PC on 4/17/2022.
// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> c(26, -1);
        int r = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (c[s[i] - 'a'] == -1) c[s[i] - 'a'] = i;
            else {
                r = max(r, i - c[s[i] - 'a'] - 1);
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    cout << s.maxLengthBetweenEqualCharacters("cbzxy");
}
