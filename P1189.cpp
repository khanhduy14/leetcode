//
// Created by Duy DA. Kieu Khanh on 11/04/2022.
// https://leetcode.com/problems/maximum-number-of-balloons/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for (int i = 0; i < text.size(); ++i) {
            m[text[i]]++;
        }

        return min(min(m['b'], min(m['a'], min(m['l'] / 2, m['o'] / 2))), m['n']);
    }
};

int main() {
    Solution s;
    cout << s.maxNumberOfBalloons("loonbalxballpoon");
}

