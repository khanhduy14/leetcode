//
// Created by PC on 5/19/2022.
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                if (pq.size() < k) pq.push({sum, {nums1[i], nums2[j]}});
                else if (sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> num1 = {1, 7, 11};
    vector<int> num2 = {2, 4, 6};
    Solution s;
    for (auto &x: s.kSmallestPairs(num1, num2, 3)) {
        cout << x[0] << " " << x[1] << endl;
    }
}
