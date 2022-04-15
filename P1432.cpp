//
// Created by PC on 4/12/2022.
// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string s1 = s, s2 = s;
        char x = '-';
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != '9' && x == '-') x = s1[i];
            if (x != '-' && s1[i] == x) s1[i] = '9';
        }

        if (s2[0] != '1') {
            x = s2[0];
            for (int i = 0; i < s2.size(); ++i) {
                if (s[i] == x) s2[i] = '1';
            }
        } else {
            x = '-';
            for (int i = 1; i < s2.size(); ++i) {
                if (s2[i] != '0' && x == '-' && s2[i] != '1') x = s[i];
                if (x != '-' && s2[i] == x) s2[i] = '0';
            }
        }
        return stoi(s1) - stoi(s2);
    }
};

int main() {
    Solution s;
    cout << s.maxDiff(111);
}
