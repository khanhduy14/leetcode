//
// Created by PC on 5/4/2022.
// https://leetcode.com/problems/max-number-of-k-sum-pairs/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int r = 0;
        while (i < j) {
            if ((nums[i] + nums[j]) == k) {
                r++;
                i++;
                j--;
            } else if ((nums[i] + nums[j]) < k) i++;
            else j--;
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 1, 3, 4, 3};
    cout << s.maxOperations(nums, 5);
}
