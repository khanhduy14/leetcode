//
// Created by PC on 5/10/2022.
// https://leetcode.com/problems/next-greater-element-ii/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MIN, mi = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > m) {
                m = nums[i];
                mi = i;
            }
        }

        vector<int> r(n);
        stack<int> s;
        for (int i = mi + 1; i <= (mi + n); ++i) {
            while (!s.empty() && nums[i % n] > nums[s.top() % n]) {
                r[s.top() % n] = nums[i % n];
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty()) {
            r[s.top() % n] = -1;
            s.pop();
        }

        r[mi] = -1;
        return r;
    }
};

int main() {
    vector<int> nums = {};
    Solution s;
    for (int x: s.nextGreaterElements(nums)) {
        cout << x << " ";
    }
}
