//
// Created by PC on 4/2/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
    }
};

int main() {
    vector<vector<int>> p = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    Solution s;
    for (auto &x: s.validArrangement(p)) {
        cout << x[0] << " " << x[1] << endl;
    }
}