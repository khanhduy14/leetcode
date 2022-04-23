//
// Created by PC on 4/18/2022.
// https://leetcode.com/problems/hand-of-straights/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> hand, int W) {
        map<int, int> c;
        for (int i : hand) c[i]++;
        for (auto it : c)
            if (c[it.first] > 0)
                for (int i = W - 1; i >= 0; --i)
                    if ((c[it.first + i] -= c[it.first]) < 0)
                        return false;
        return true;
    }
};

int main() {
    Solution s;
    vector<int> h = {1, 2, 3};
    cout << s.isNStraightHand(h, 1);
}
