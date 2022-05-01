//
// Created by Duy DA. Kieu Khanh on 01/05/2022.
// https://leetcode.com/problems/reach-a-number/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        int r = 0;
        target = abs(target);
        while (true) {
            r++;
            target -= r;
            if (target == 0 || (target < 0 && -target % 2 == 0)) break;
        }

        return r;
    }
};

int main() {
    Solution s;
    cout << s.reachNumber(1);
}
