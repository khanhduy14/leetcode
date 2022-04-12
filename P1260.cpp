//
// Created by PC on 4/11/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = (i + (j + k) / n) % m;
                int y = (j + k) % n;
                res[x][y] = grid[i][j];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> g = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    for (auto &x: s.shiftGrid(g, 1)) {
        for (auto &a: x) {
            cout << a << " ";
        }
        cout << endl;
    }
}
