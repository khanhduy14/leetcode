//
// Created by PC on 5/8/2022.
// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end(), comp);
        int m = INT_MIN;
        int r = 0;

        for (int i = properties.size() - 1; i >= 0; i--) {
            if (properties[i][1] < m)
                r++;
            m = max(m, properties[i][1]);
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<vector<int>> pro = {{1, 2},
                               {1, 1},
                               {2, 2},
                               {2, 1}};
    cout << s.numberOfWeakCharacters(pro);
}
