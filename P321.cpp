//
// Created by PC on 5/11/2022.
// https://leetcode.com/problems/create-maximum-number/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> s1;
        vector<int> s2;
        int n1 = nums1.size(), n2 = nums2.size();
        int del = n1 + n2 - k;
        int i = 0, j = 0;
        while (!(i >= n1 && j >= n2)) {
            if (del == 0) {
                for (; i < n1; ++i) {
                    s1.push_back(nums1[i]);
                }
                for (; j < n2; ++j) {
                    s2.push_back(nums2[j]);
                }
            }
            if (j == n2 || nums1[i] > nums2[j]) {

                while (!s1.empty() && s1.back() < nums1[i] && del > 0) {
                    s1.pop_back();
                    del--;
                }
                s1.push_back(nums1[i]);
                while (!s2.empty() && s2.back() < nums1[i] && del > 0) {
                    s2.pop_back();
                    del--;
                }
                i++;
            } else {
                while (!s2.empty() && s2.back() < nums2[j] && del > 0) {
                    s2.pop_back();
                    del--;
                }
                s2.push_back(nums2[j]);
                while (!s1.empty() && s1.back() < nums2[j] && del > 0) {
                    s1.pop_back();
                    del--;
                }
                j++;
            }
        }
        i = 0, j = 0;
        vector<int> r;
        for (int x: s2) {
            cout << x << " ";
        }
        cout << endl;

        return r;
    }
};

int main() {
    Solution s;
    vector<int> n1 = {3,9};
    vector<int> n2 = {8,9};
    for (int x: s.maxNumber(n1, n2, 3)) {
        cout << x << " ";
    }
}
