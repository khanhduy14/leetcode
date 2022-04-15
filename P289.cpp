//
// Created by PC on 4/12/2022.
// https://leetcode.com/problems/game-of-life/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> k = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                for (auto &t: k) {
                    int x = i - t[0]; int y = j - t[1];
                    if (x >= 0 && y >= 0 && x < m && y < n) {
                        if (board[x][y] > 1) {
                            sum += board[x][y] % 2;
                        } else {
                            sum += board[x][y];
                        }
                    }
                }
                board[i][j] += (sum << 1);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int y = board[i][j] / 2;
                int x = board[i][j] % 2;

                board[i][j] = x;
                if (x == 1 && y < 2) board[i][j] = 0;
                if (x == 1 && y > 3) board[i][j] = 0;
                if (x == 0 && y == 3) board[i][j] = 1;
                if (x == 1 && (y == 2 || y == 3)) board[i][j] = 1;
            }
        }
    }
};

int main() {
    vector<vector<int>> b = {{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
    Solution s;
    s.gameOfLife(b);
}
