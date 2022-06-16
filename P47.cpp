//
// Created by PC on 5/12/2022.
// https://leetcode.com/problems/permutations-ii/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    unordered_map<int, int> m;
    vector<vector<int>> r;
    int n;
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        n = nums.size();
        for (int num: nums) {
            m[num]++;
        }
        vector<int> t;
        generatePermute(t);
        return r;
    }

    void generatePermute(vector<int> &x) {
        if (x.size() == n) r.push_back(x);
        for (auto &kv: m) {
            if (kv.second == 0) continue;
            m[kv.first]--;
            x.push_back(kv.first);
            generatePermute(x);
            x.pop_back();
            m[kv.first]++;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    for (auto &x: s.permuteUnique(nums)) {
        for (int a: x) {
            cout << a << " ";
        }

        cout << endl;
    }
}
