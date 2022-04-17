//
// Created by Duy DA. Kieu Khanh on 16/04/2022.
// https://leetcode.com/problems/valid-parenthesis-string/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> q;
        stack<int> qs;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') qs.push(i);
            if (s[i] == '(') q.push(i);
            if (s[i] == ')') {
                if (q.empty() && qs.empty()) return false;
                if (q.empty()) { qs.pop(); continue; }
                if (!q.empty()) { q.pop(); continue; }
            }
        }
        while (!q.empty() && !qs.empty()) {
            int f = q.top(); q.pop();
            int fs = qs.top(); qs.pop();
            if (f > fs) return false;
        }

        return q.empty();
    }
};

int main() {
    Solution s;
    cout << s.checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()");
}
// (*(*)