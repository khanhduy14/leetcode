//
// Created by PC on 4/23/2022.
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = i * 2 - n + 1;
        return A;
    }
};

int main() {
    Solution s;
    for (int x: s.sumZero(5)) {
        cout << x << " ";
    }
}