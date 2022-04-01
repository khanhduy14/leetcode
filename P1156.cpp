//
// Created by PC on 3/31/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> ct[26];
        for (int i = 0; i < text.size(); ++i) {
            ct[text[i] - 'a'].push_back(i);
        }
        int m = 0;
        for (auto &x: ct) {
            m = max((int)x.size(), m);
        }
    }
};

int main() {
    Solution s;
    cout << s.maxRepOpt1("ababa");
}
