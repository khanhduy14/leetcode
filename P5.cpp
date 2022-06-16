//
// Created by PC on 6/16/2022.
// https://leetcode.com/problems/longest-palindromic-substring/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int maxL = 1;
        int x, y, start = 0;
        for (int i = 1; i < len; ++i) {
            x = i - 1;
            y = i;

            while (x >= 0 && y < len && s[x] == s[y]) {
                --x;
                ++y;
            }
            ++x;
            --y;
            if (s[x] == s[y] && y - x + 1 > maxL) {
                start = x;
                maxL = y - x + 1;
            }

            x = i - 1;
            y = i + 1;

            while (x >= 0 && y < len && s[x] == s[y]) {
                --x;
                ++y;
            }
            ++x;
            --y;
            if (s[x] == s[y] && y - x + 1 > maxL) {
                start = x;
                maxL = y - x + 1;
            }

        }
        return s.substr(start, maxL);
    }
};
