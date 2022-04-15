//
// Created by PC on 4/13/2022.
// https://leetcode.com/problems/find-center-of-star-graph/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>> &A) {
        return ((A[0][0] == A[1][0]) || (A[0][0] == A[1][1])) ? A[0][0] : A[0][1];
    }
};

int main() {
    vector<vector<int>> e = {{1, 2},
                             {2, 3},
                             {4, 2}};
    Solution s;
    cout << s.findCenter(e);
}
