//
// Created by PC on 4/23/2022.
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] = arr[i] ^ arr[i - 1];
        }
        int r = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == 0) r += i;
            for (int j = 0; j < i; ++j) {
                if (arr[i] == arr[j]) r += i - j - 1;
            }

        }
        return r;
    }
};

int main() {
    vector<int> arr = {2,3,1,6,7};
    Solution s;
    cout << s.countTriplets(arr);
}

//1 0 1 0 1
