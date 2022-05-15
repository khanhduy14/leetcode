//
// Created by Duy DA. Kieu Khanh on 15/05/2022.
// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int> &cards) {
        int r = INT_MAX;
        unordered_map<int, int> m;
        for (int i = 0; i < cards.size(); ++i) {
            if (m.count(cards[i])) {
                r = min(r, i - m[cards[i]] + 1);
                m[cards[i]] = i;
                continue;
            }
            m[cards[i]] = i;
        }
        return r == INT_MAX ? -1 : r;
    }
};

int main() {
    Solution s;
    vector<int> cards = {3, 4, 2, 3, 4, 7};
    cout << s.minimumCardPickup(cards);
}
