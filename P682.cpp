//
// Created by Duy DA. Kieu Khanh on 10/04/2022.
// https://leetcode.com/problems/baseball-game/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calPoints(vector<string> &ops) {
        int value1;
        int value2;
        int ans = 0;
        stack<int> stk;

        for (string i: ops) {
            if (i == "C") {
                stk.pop();
            } else if (i == "D") {
                stk.push(stk.top() * 2);
            } else if (i == "+") {
                value1 = stk.top();
                stk.pop();
                value2 = stk.top();
                stk.push(value1);
                stk.push(value1 + value2);
            } else {
                stk.push(stoi(i));
            }
        }
        while (stk.size() != 0) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> o = {"5", "2", "C", "D", "+"};
    cout << s.calPoints(o);
}
