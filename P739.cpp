//
// Created by PC on 5/7/2022.
// https://leetcode.com/problems/daily-temperatures/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &A) {
        int n = A.size();
        stack<int> s;
        vector<int> r(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && A[s.top()] <= A[i]) {
                s.pop();
            }
            if (s.empty()) r[i] = 0;
            else {
                r[i] = s.top() - i;
            }
            s.push(i);
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<int> temp = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
    for (int x: s.dailyTemperatures(temp)) {
        cout << x << " ";
    }
}
