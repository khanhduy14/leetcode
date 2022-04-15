//
// Created by PC on 4/13/2022.
// https://leetcode.com/problems/spiral-matrix-ii/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> s = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(n, vector<int>(n, 0));
        int t = 1, i = 0, j = 0;
        int m = 0;
        while (t <= n*n) {
            res[i][j] = t;
            t++;
            int k = 2;
            while (k--) {
                int x = i + s[m][0];
                int y = j + s[m][1];
                if (x >= 0 && y >= 0 && x < n && y < n && !res[x][y]) {
                    i = x; j = y;
                    break;
                } else {
                    m = (m + 1) % 4;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    for (auto &x: s.generateMatrix(1)) {
        for (auto &k: x) {
            cout << k << " ";
        }

        cout << endl;
    }
}
