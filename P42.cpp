//
// Created by PC on 4/5/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &h) {
        int m1 = 0, m2 = 0;
        int r = 0;
        int i = 0, j = h.size() - 1;
        while (i < j) {
            r += h[i] < m1 ? (m1 - h[i]) : 0;
            m1 = max(m1, h[i]);
            r += h[j] < m2 ? (m2 - h[j]) : 0;
            m2 = max(m2, h[j]);
            if (m1 > m2) j--;
            else i++;
        }
        return r;
    }
};

int main() {
    vector<int> h = {4,2,0,3,2,5};
    Solution s;
    cout << s.trap(h);
}