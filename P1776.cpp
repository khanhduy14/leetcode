//
// Created by PC on 5/10/2022.
// https://leetcode.com/problems/car-fleet-ii/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>> &A) {
        int n = A.size();
        vector<int> stack;
        vector<double> res(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            int p = A[i][0], s = A[i][1];
            while (!stack.empty()) {
                int j = stack.back(), p2 = A[j][0], s2 = A[j][1];
                if (s <= s2 || 1.0 * (p2 - p) / (s - s2) >= res[j] && res[j] > 0)
                    stack.pop_back();
                else
                    break;
            }
            if (!stack.empty())
                res[i] = 1.0 * (A[stack.back()][0] - p) / (s - A[stack.back()][1]);
            stack.push_back(i);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> cars = {{3, 4},
                                {5, 4},
                                {6, 3},
                                {9, 1}};
    Solution s;
    for (double x: s.getCollisionTimes(cars)) {
        cout << x << " ";
    }
}
