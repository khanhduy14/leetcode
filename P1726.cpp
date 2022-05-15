//
// Created by Duy DA. Kieu Khanh on 03/05/2022.
// https://leetcode.com/problems/tuple-with-same-product/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        unordered_map<long, int> m;
        int r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (m.count(nums[i] * nums[j])) {
                    r += 8 * m[nums[i] * nums[j]];
                }
                m[nums[i] * nums[j]]++;
            }
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 4, 6, 8, 12};
    cout << s.tupleSameProduct(nums);
}

//26 / 34
//38 / 212
//45 / 212
//38 / 64
//68 / 412