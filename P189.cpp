//
// Created by Duy DA. Kieu Khanh on 03/05/2022.
// https://leetcode.com/problems/rotate-array/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        int z = k;
        int i = 0;
        while (--z >= 0 && i < n) {
            int x = nums[z];
            for (int j = z + k; (j % n) != z; j = j + k) {
                i++;
                swap(nums[j % n], x);
            }
            i++;
            nums[z] = x;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,-100,3,99};
    s.rotate(nums, 2);
    for (int x: nums) {
        cout << x << " ";
    }
}
