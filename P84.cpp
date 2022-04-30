//
// Created by PC on 4/27/2022.
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &H) {
        int n = H.size();
        stack<int> s;
        s.push(0);
        int r = 0;
        for (int i = 1; i < n + 1; ++i) {
            while (!s.empty() && (i == n || H[s.top()] > H[i])) {
                int t = s.top();
                s.pop();
                r = max(r, H[t] * (i - (s.empty() ? 0 : s.top() + 1)));
            }
            s.push(i);
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<int> h = {2, 4};
    cout << s.largestRectangleArea(h);
}
