//
// Created by PC on 4/22/2022.
// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> m(26, 0);
        for (char c: s) {
            m[c - 'a']++;
        }
        int r = 0;
        sort(m.begin(), m.end());
        for (int i = 1; i < 26; ++i) {
            if (m[i] != 0) {
                int j = 1;
                while ((i - j >= 0) && (m[i] > 0)) {
                    if (m[i] == m[i - j]) {
                        r++;
                        m[i]--;
                        j++;
                    } else {
                        break;
                    }
                }
                int t = m[i];
                for (int k = i; k > i - j + 1; --k) {
                     m[k] = m[k - 1];
                }
                m[i - j + 1] = t;
            }
        }

        return r;
    }
};

int main() {
    Solution s;
    cout << s.minDeletions("abcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwz");
}
