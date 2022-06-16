//
// Created by PC on 5/9/2022.
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<char>> temp = {{'a', 'b', 'c'},
                                 {'d', 'e', 'f'},
                                 {'g', 'h', 'i'},
                                 {'j', 'k', 'l'},
                                 {'m', 'n', 'o'},
                                 {'p', 'q', 'r', 's'},
                                 {'t', 'u', 'v'},
                                 {'w', 'x', 'y', 'z'}};
    vector<string> r;
    vector<string> letterCombinations(string digits) {
        getString(digits, "", 0);
        return r;
    }

    void getString(string digits, string res, int i) {
        if (i >= digits.size()) {
            if (res != "") r.push_back(res);
            return;
        }
        for (char x: temp[digits[i] - '0' - 2]) {
            getString(digits, res + x, i + 1);
        }
    }
};

int main() {
    Solution s;
    for (string x: s.letterCombinations("2")) {
        cout << x << endl;
    }
}
