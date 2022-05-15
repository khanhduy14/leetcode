//
// Created by Duy DA. Kieu Khanh on 15/05/2022.
// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums, int k) {
        int r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j] && (i * j) % k == 0) r++;
            }
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    cout << s.countPairs(nums, 2)
}
