//
// Created by PC on 5/17/2022.
// https://leetcode.com/problems/max-chunks-to-make-sorted/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        int r = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int m = arr[i];
            while (i < m) {
                i++;
                m = max(m, arr[i]);
            }
            r++;
        }
        return r;
    }
};

int main() {
    vector<int> arr = {1,0,2,3,4};
    Solution s;
    cout << s.maxChunksToSorted(arr);
}
