//
// Created by PC on 4/7/2022.
// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int> lis;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (lis.empty() || lis[lis.size() - 1] <= x) {
                lis.push_back(x);
                nums[i] = lis.size();
            } else {
                int idx = upper_bound(lis.begin(), lis.end(), x) - lis.begin();
                lis[idx] = x;
                nums[i] = idx + 1;
            }
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 3, 2};
    for (auto &x: s.longestObstacleCourseAtEachPosition(a)) {
        cout << x << endl;
    }
}

