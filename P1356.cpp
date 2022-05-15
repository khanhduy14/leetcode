//
// Created by Duy DA. Kieu Khanh on 14/05/2022.
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int> &arr) {
        vector<vector<int>> m(15);
        sort(arr.begin(), arr.end());
        for (int i : arr) {
            m[count1(i)].push_back(i);
        }
        vector<int> r;
        for (auto &p: m) {
            for (int x: p) {
                r.push_back(x);
            }
        }

        return r;
    }

private:
    int count1(int a) {
        int r = 0;
        while (a > 0) {
            if (a % 2 != 0) {
                r++;
                a--;
            }
            else a /= 2;
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int x: s.sortByBits(arr)) {
        cout << x << " ";
    }
}