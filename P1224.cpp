//
// Created by PC on 4/20/2022.
// https://leetcode.com/problems/maximum-equal-frequency/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int> &A) {
        vector<int> count(100001), freq(100001);
        int res = 0, N = A.size(), a, c, d;
        for (int n = 1; n <= N; ++n) {
            a = A[n - 1];
            --freq[count[a]];
            c = ++count[a];
            ++freq[count[a]];

            if (freq[c] * c == n && n < N)
                res = n + 1;
            d = n - freq[c] * c;
            if ((d == c + 1 || d == 1) && freq[d] == 1)
                res = n;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1, 2, 3, 4, 4, 4, 4, 1, 2, 3, 5, 6};
    cout << s.maxEqualFreq(nums);
}