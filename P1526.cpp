//
// Created by PC on 5/4/2022.
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int> &target) {
        int r = 0;
        int mi = target[0], ma = target[0], p_mi = 0;
        for (int x: target) {
            if (x > mi) {
                r += (ma - p_mi);
                p_mi = mi;
                ma = x;
            }
            mi = x;
        }

        return r + ma - p_mi;
    }
};

int main() {
    Solution s;
    vector<int> target = {1,2,3,2,1};
    cout << s.minNumberOperations(target);
}
