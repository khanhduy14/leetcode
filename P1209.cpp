//
// Created by PC on 5/6/2022.
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (char c: s) {
            if (st.empty() || c != st.top().first) st.push({c, 1});
            else if (!st.empty() && st.top().second == (k - 1)) st.pop();
            else {
                pair<char, int> f = st.top();
                st.pop();
                st.push({c, f.second + 1});
            }
        }

        string r = "";
        while (!st.empty()) {
            pair<char, int> f = st.top();
            st.pop();
            for (int i = 0; i < f.second; ++i) {
                r += f.first;
            }
        }
        reverse(r.begin(), r.end());
        return r;
    }
};

int main() {
    Solution s;
    cout << s.removeDuplicates("pbbcggttciiippooaais", 2);
}
