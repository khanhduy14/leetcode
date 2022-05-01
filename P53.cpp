//
// Created by Duy DA. Kieu Khanh on 01/05/2022.
// https://leetcode.com/problems/maximum-subarray/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int mi = 0, ma = INT_MIN;
        int s = 0;
        for (int n: nums) {
            s += n;
            ma = max(ma, s - mi);
            mi = min(mi, s);
        }

        return ma;
    }
};

int main() {
    Solution s;
    vector<int> n = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(n);
}
