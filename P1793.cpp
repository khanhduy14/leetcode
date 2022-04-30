//
// Created by PC on 4/25/2022.
// https://leetcode.com/problems/maximum-score-of-a-good-subarray/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumScore(vector<int> &A, int k) {
        int res = A[k], mini = A[k], i = k, j = k, n = A.size();
        while (i > 0 or j < n - 1) {
            if ((i > 0 ? A[i - 1] : 0) < (j < n - 1 ? A[j + 1] : 0))
                mini = min(mini, A[++j]);
            else
                mini = min(mini, A[--i]);
            res = max(res, mini * (j - i + 1));
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 4, 3, 7, 4, 5};
    cout << s.maximumScore(nums, 3);
}
