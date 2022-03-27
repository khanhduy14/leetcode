#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        vector<int> res;
        vector<int> m[mat[0].size() + 1];
        for (int i = 0; i < mat.size(); ++i) {
            int ct = 0;
            for (auto &x: mat[i]) {
                if (x == 0) break;
                ++ct;
            }
            m[ct].push_back(i);
        }

        for (auto &v: m) {
            for (auto &x: v) {
                res.push_back(x);
                k--;
                if (k == 0) return res;
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};
    for (auto &x: s.kWeakestRows(a, 3)) {
        cout << x << endl;
    }
}