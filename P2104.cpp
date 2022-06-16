//
// Created by PC on 5/15/2022.
// https://leetcode.com/problems/sum-of-subarray-ranges/

#include "bits/stdc++.h"

using namespace std;
#define ll long long

class Solution {
public:
    long long subArrayRanges(vector<int> &A) {
        long res = 0, n = A.size(), j, k;
        stack<int> s;
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && A[s.top()] > (i == n ? -2e9 : A[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res -= (long) A[j] * (i - j) * (j - k);
                cout << res << endl;
            }
            s.push(i);
        }
        s = stack<int>();
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && A[s.top()] < (i == n ? 2e9 : A[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res += (long) A[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,2,4};
    cout << s.subArrayRanges(nums);
}
