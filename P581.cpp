//
// Created by Duy DA. Kieu Khanh on 03/05/2022.
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        stack<int> s;
        int st = INT_MAX, fn = INT_MIN, m = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                st = min(st, s.top());
                m = max(m, nums[s.top()]);
                s.pop();
                fn = i;
            }
            if (nums[i] < m) fn = i;
            s.push(i);
        }
        return st == INT_MAX ? 0 : (fn - st + 1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,3,2,4};
    cout << s.findUnsortedSubarray(nums);
}
