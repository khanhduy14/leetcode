//
// Created by PC on 5/19/2022.
// https://leetcode.com/problems/check-if-n-and-its-double-exist/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int> &arr) {
        unordered_map<int, bool> m;
        for (int x: arr) {
            if (m.count(x)) return true;
            m[2 * x] = true;
            if (x % 2 == 0) m[x / 2] = true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> arr = {10, 2, 5, 3};
    cout << s.checkIfExist(arr);
}
