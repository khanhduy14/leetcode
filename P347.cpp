//
// Created by PC on 4/9/2022.
// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }

        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int) map.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

int main() {
    vector<int> a = {1};
    Solution s;
    for (auto &x: s.topKFrequent(a, 1)) {
        cout << x << " ";
    }
}
