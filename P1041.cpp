//
// Created by PC on 5/3/2022.
// https://leetcode.com/problems/robot-bounded-in-circle/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> st = {0, 0};
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int curDic = 1;
        for (int i = 0; i < 4; ++i) {
            for (char c: instructions) {
                if (c == 'L') curDic = (curDic + 3) % 4;
                if (c == 'R') curDic = (curDic + 1) % 4;
                if (c == 'G') {
                    st = {st[0] + dir[curDic][0], st[1] + dir[curDic][1]};
                }
            }
        }
        return st[0] == 0 && st[1] == 0;
    }
};

int main() {
    Solution s;
    cout << s.isRobotBounded("GG");
}
