//
// Created by PC on 5/9/2022.
// https://leetcode.com/problems/car-fleet/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // using map instead of array for better performant (O(n) & O(1)), cause we don't need to sort array anymore
    // TODO: for next time :D
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = position.size();
        vector<vector<float>> v;
        for (int i = 0; i < n; ++i) {
            v.push_back({(float )position[i], (float ) (target - position[i]) / (float )speed[i]});
        }
        sort(v.begin(), v.end());
        int r = 0; double m = FLT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            if (v[i][1] > m) {
                r++;
                m = v[i][1];
            }
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<int> p = {8,3,7,4,6,5};
    vector<int> sp = {4,4,4,4,4,4};
    cout << s.carFleet(10, p, sp);
}
