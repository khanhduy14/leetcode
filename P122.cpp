//
// Created by Duy DA. Kieu Khanh on 15/05/2022.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int r = 0;
        int mi = INT_MAX;
        int ma = INT_MIN;
        for (int price: prices) {
            if (price < ma) {
                r += (ma - mi);
                mi = price;
                ma = INT_MIN;
                continue;
            }
            if (price < mi) {
                mi = price;
                continue;
            }
            if (price > ma) {
                ma = price;
            }
        }

        return ma != INT_MIN && mi != INT_MAX ? r + ma - mi : r;
    }
};

int main() {
    Solution s;
    vector<int> prices = {1,2,3,4,5};
    cout << s.maxProfit(prices);
}
