//
// Created by PC on 4/11/2022.
// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        unordered_map<string, int> m;
        priority_queue<pair<int, string>> q;
        vector<string> res;
        for (int i = 0; i < list1.size(); ++i) {
            m[list1[i]] = i + 1;
        }

        for (int i = 0; i < list2.size(); ++i) {
            if (m[list2[i]]) q.push({-(m[list2[i]] + i), list2[i]});
        }

        int mi = q.top().first;
        while (!q.empty()) {
            if (mi == q.top().first) {
                res.push_back(q.top().second);
                q.pop();
            } else {
                break;
            }
        }

        return res;
    }
};

int main() {
    vector<string> l1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> l2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    Solution s;
    for (auto &x: s.findRestaurant(l1, l2)) {
        cout << x << " ";
    }
}
