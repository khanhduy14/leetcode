//
// Created by PC on 4/1/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++; j--;
        }
    }
};

int main() {
    Solution s;
    vector<char> a = {};
    s.reverseString(a);
    for (auto &c: a) {
        cout << c << endl;
    }
}
