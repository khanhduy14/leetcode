//
// Created by PC on 4/2/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j]) {
                int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
                while (i1 < j1 && s[i1] == s[j1]) {
                    i1++;
                    j1--;
                };
                while (i2 < j2 && s[i2] == s[j2]) {
                    i2++;
                    j2--;
                };
                return i1 >= j1 || i2 >= j2;
            }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("abca");
}
//5 15