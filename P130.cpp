//
// Created by Duy DA. Kieu Khanh on 14/05/2022.
// https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        vector<vector<int>> k = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' || dp[i][j]) continue;
                queue<pair<int, int>> q;
                q.push({i, j});
                vector<vector<int>> stackTemp;
                stackTemp.push_back({i, j});
                int flag = i == 0 || j == 0 || i == (m - 1) || j == (n - 1);
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    if (dp[x][y]) continue;
                    dp[x][y] = true;
                    for (vector<int> &z: k) {
                        int xn = z[0] + x;
                        int yn = z[1] + y;
                        if (xn >= 0 && xn < m && yn >= 0 && yn < n && !dp[xn][yn] && board[xn][yn] == 'O') {
                            if (xn == 0 || yn == 0 || xn == (m - 1) || yn == (n - 1)) flag = true;
                            q.push({xn, yn});
                            stackTemp.push_back({xn, yn});
                        }
                    }
                }
                if (!flag) {
                    for (vector<int> &c: stackTemp) {
                        board[c[0]][c[1]] = 'X';
                    }
                }
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    s.solve(board);

    for (vector<char> &a: board) {
        for (char c: a) {
            cout << c << " ";
        }

        cout << endl;
    }
}
