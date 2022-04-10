//
// Created by Duy DA. Kieu Khanh on 11/04/2022.
// https://leetcode.com/problems/height-checker/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int> &heights) {
        vector<int> h = heights;
        sort(heights.begin(), heights.end());
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (h[i] != heights[i]) res++;
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> h = {1, 1, 4, 2, 1, 3};
    cout << s.heightChecker(h);
}
