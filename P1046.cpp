//
// Created by PC on 4/7/2022.
// https://leetcode.com/problems/last-stone-weight/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> q;
        for (auto &x: stones) {
            q.push(x);
        }
        while (q.size() > 1) {
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            q.push(a - b);
        }
        return q.top();
    }
};

int main() {
    vector<int> a = {7, 6, 7, 6, 9};
    Solution s;
    cout << s.lastStoneWeight(a);
}
