//
// Created by PC on 4/20/2022.
// https://leetcode.com/problems/maximum-equal-frequency/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int> &nums) {
        int n = nums.size();
        int r = 1;
        unordered_map<int, int> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q_mi;
        priority_queue<pair<int, int>> q_ma;
        for (int i = 0; i < n; ++i) {
            m[nums[i]]++;
            q_ma.push({m[nums[i]], nums[i]});
            if (q_mi.empty() || nums[i] != q_mi.top().second) {
                q_mi.push({m[nums[i]], nums[i]});
            } else {
                q_mi.pop();
                q_mi.push({m[nums[i]], nums[i]});
            }

            if (q_mi.top().first == 1) {
                pair<int, int> t = q_mi.top();
                q_mi.pop();
                cout << 1 << i << " " << q_ma.top().first << " " << q_mi.top().first << endl;
                if (q_ma.top().first == q_mi.top().first) r = i + 1;
                q_mi.push(t);
            } else {
                if (q_ma.top().first == (q_mi.top().first + 1)) {
                    pair<int, int> t = q_ma.top();
                    q_ma.pop();
                    cout << 2 << i << " " << q_ma.top().first << " " << q_mi.top().first << endl;
                    if (q_ma.top().first == q_mi.top().first) r = i + 1;
                    q_ma.push(t);
                }
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 2, 8, 9, 3, 8, 1, 5, 2, 3, 7, 6};
    cout << s.maxEqualFreq(nums);
}