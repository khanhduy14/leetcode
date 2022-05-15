//
// Created by Duy DA. Kieu Khanh on 15/05/2022.
// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2) {
        int i = 0, j = 0;
        int r = 0;
        while (j < nums2.size() && i < nums1.size()) {
            if (i > j) {
                j++;
                continue;
            }
            if (nums1[i] <= nums2[j]) {
                r = max(r, j - i);
                j++;
                continue;
            }
            i++;
        }

        return r;
    }
};
