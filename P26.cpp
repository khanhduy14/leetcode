//
// Created by PC on 4/20/2022.
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int i = 0, j = 0;
        while (j < A.size()) {
            if (A[i] != A[j]) {
                swap(A[j], A[i + 1]);
                i++;
            }
            j++;
        }

        return i + 1;
    }
};

int main() {
    vector<int> n = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    cout << s.removeDuplicates(n);
}

