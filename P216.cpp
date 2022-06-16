//
// Created by PC on 5/10/2022.
// https://leetcode.com/problems/combination-sum-iii/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> r;
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n < (k * (k + 1) / 2) || n > ((45 - (9 - k) * (10 - k) / 2))) return {};
        getSum(k, n, 1, {});
        return r;
    }

    void getSum(int k, int n, int s, vector<int> rt) {
        if (k == 0 || n == 0) {
            if (k == 0 && n == 0) r.push_back(rt);
            return;
        }

        for (int i = s; i < 10 && i <= n; ++i) {
            rt.push_back(i);
            getSum(k - 1, n - i, i + 1, rt);
            rt.pop_back();
        }
    }
};

int main() {
    Solution s;
    for (auto &x: s.combinationSum3(3, 7)) {
        for (int a: x) {
            cout << a << " ";
        }
        cout << endl;
    }
}
