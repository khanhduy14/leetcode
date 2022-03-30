//
// Created by PC on 3/30/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &a, int target) {
        int m = a.size();
        int n = a[0].size();

        if (m == 1) return bs(a[0], target);

        for (int i = 0; i < m - 1; ++i) {
            if (a[i][0] <= target && a[i + 1][0] > target) {
                return bs(a[i], target);
            }
        }
        return bs(a[m - 1], target);
    }

    bool bs(vector<int> &a, int target) {
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int m = (l + r + 1) / 2;
            if (a[m] == target) return true;
            if (a[m] > target) r = m - 1;
            if (a[m] < target) l = m + 1;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = {{1,  3,  5,  7},
                             {10, 11, 16, 20},
                             {23, 30, 34, 60}};
    cout << s.searchMatrix(a, 3);
}
