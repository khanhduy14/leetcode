//
// Created by Duy DA. Kieu Khanh on 02/05/2022.
// https://leetcode.com/problems/sort-array-by-parity/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] % 2 == 0) {
                i++;
                continue;
            }
            if (nums[j] % 2 == 1) {
                j--;
                continue;
            }
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0};
    for (int x: s.sortArrayByParity(nums)) {
        cout << x << " ";
    }
}
