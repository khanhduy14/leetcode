//
// Created by PC on 5/7/2022.
// https://leetcode.com/problems/find-the-most-competitive-subsequence/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        vector<int> s;
        int n = nums.size();
        for (int a: nums) {
            while (!s.empty() && s.back() > a && (s.size() + n) > k) {
                s.pop_back();
            }
            s.push_back(a);
            n--;
        }

        vector<int> r;
        for (int i = 0; i < k; ++i) {
            r.push_back(s[i]);
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 4, 3, 3, 5, 4, 9, 6};
    for (int x: s.mostCompetitive(nums, 4)) {
        cout << x << " ";
    }
}
