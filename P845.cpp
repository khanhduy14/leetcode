//
// Created by Duy DA. Kieu Khanh on 11/04/2022.
// https://leetcode.com/problems/longest-mountain-in-array/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int> &arr) {
        if (arr.size() < 3) return 0;

        int res = 0;

        for (int i = 0; i < arr.size(); ++i) {
            int u = 0;
            int d = 0;
            for (; i < arr.size() - 1; ++i) {
                if (arr[i + 1] <= arr[i]) break;
                u++;
            }

            if (u == 0) continue;
            for (int j = i + 1; j < arr.size(); ++j) {
                if (arr[j] >= arr[j - 1]) break;
                d++;
            }
            if (d == 0) continue;
            res = max(res, d + u + 1);
        }

        return res;
    }
};


int main() {
    vector<int> arr = {2,1,4,7,3,2,5};
    Solution s;
    cout << s.longestMountain(arr);
}
