//
// Created by PC on 4/28/2022.
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int> &A) {
        vector<int> stack;
        for (int i = 0; i < A.size(); ++i) {
            while (stack.size() && A[stack.back()] >= A[i]) {
                A[stack.back()] -= A[i];
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return A;
    }
};

int main() {
    vector<int> prices = {8, 4, 6, 2, 3};
    Solution s;
    for (int x: s.finalPrices(prices)) {
        cout << x << endl;
    }
}