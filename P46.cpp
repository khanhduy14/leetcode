//
// Created by PC on 4/3/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        permuteRecursive(num, 0, result);
        return result;
    }

    void permuteRecursive(vector<int> &num, int begin, vector<vector<int>> &result) {
        if (begin >= num.size()) {
            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            swap(num[begin], num[i]);
        }
    }
};

int main() {
    vector<int> a = {1};
    Solution s;
    for (auto &x: s.permute(a)) {
        for (auto &u: x) {
            cout << u << " ";
        }
        cout << endl;
    }
}