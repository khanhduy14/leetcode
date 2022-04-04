//
// Created by PC on 4/4/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int> &a) {
        bool f = a[0] > a[a.size() - 1];
        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i] == a[i + 1]) continue;
            if ((a[i] > a[i + 1]) != f) return false;
        }

        return true;
    }
};

int main() {
    vector<int> a = {1,3,2};
    Solution s;
    cout << s.isMonotonic(a);
}
