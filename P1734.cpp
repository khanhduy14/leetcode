//
// Created by PC on 4/18/2022.
// https://leetcode.com/problems/decode-xored-permutation/
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &A) {
        int n = A.size() + 1, a = 0;
        for (int i = 0; i <= n; ++i) {
            a ^= i;
            if (i < n && i % 2 == 1) {
                a ^= A[i];
            }
        }
        vector<int> res = {a};
        for (int a: A) {
            res.push_back(res.back() ^ a);
        }
        return res;
    }
};

int main() {
    vector<int> en = {12, 6, 11, 10, 5, 3, 4, 6};
    Solution s;
    cout << (s.decode(en) == vector<int>{8, 4, 2, 9, 3, 6, 5, 1, 7});
}