//
// Created by PC on 4/14/2022.
// https://leetcode.com/problems/minimum-moves-to-convert-string/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'X') {
                res++;
                for (int j = 0; j < 3 && (i + j) < s.size(); ++j) {
                    s[j + i] = 'O';
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.minimumMoves("XXXXX");
}