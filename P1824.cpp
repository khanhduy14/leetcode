//
// Created by PC on 4/7/2022.
// https://leetcode.com/problems/minimum-sideway-jumps/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSideJumps(vector<int> &obstacles) {
        int dp[] = {1, 0, 1};
        for (int a: obstacles) {
            if (a > 0)
                dp[a - 1] = 1e6;
            for (int i = 0; i < 3; ++i)
                if (a != i + 1)
                    dp[i] = min(dp[i], min(dp[(i + 1) % 3], dp[(i + 2) % 3]) + 1);
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};

int main() {
    vector<int> a = {0, 2, 1, 0, 3, 0};
    Solution s;
    cout << s.minSideJumps(a);
}
