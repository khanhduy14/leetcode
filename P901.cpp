//
// Created by PC on 5/12/2022.
// https://leetcode.com/problems/online-stock-span/

#include "bits/stdc++.h"

using namespace std;

class StockSpanner {
public:
    StockSpanner() {

    }

    stack<pair<int, int>> s;
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};
