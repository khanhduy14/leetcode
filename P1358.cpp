//
// Created by PC on 4/12/2022.
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0}, res = 0, i = 0, n = s.length();
        for (int j = 0; j < n; ++j) {
            ++count[s[j] - 'a'];
            while (count[0] && count[1] && count[2])
                --count[s[i++] - 'a'];
            res += i;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.numberOfSubstrings("abc");
}
