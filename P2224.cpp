//
// Created by PC on 4/11/2022.
// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    int getTime(string &s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }
public:
    int convertTime(string current, string correct) {
        int diff = getTime(correct) - getTime(current), ops[4] = {60,15,5,1}, ans = 0;
        for (int op : ops) {
            ans += diff / op;
            diff %= op;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.convertTime("02:30", "04:35");
}
