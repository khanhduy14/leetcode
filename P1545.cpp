//
// Created by Duy DA. Kieu Khanh on 01/05/2022.
// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while (n-- > 1) {
            s = convert(s);
        }
        return s[k - 1];
    }

private:
    string convert(string s) {
        string inv_s;
        for (int i = s.size() - 1; i >= 0; --i) {
            inv_s += s[i] == '0' ? "1" : "0";
        }
        return s + "1" + inv_s;
    }
};

int main() {
    Solution s;
    cout << s.findKthBit(3, 1);
}
