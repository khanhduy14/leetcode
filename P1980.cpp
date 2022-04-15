//
// Created by PC on 4/14/2022.
// https://leetcode.com/problems/find-unique-binary-string/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < pow(2, n); ++i) {
            if (i >= n || i != convert(nums[i], n)) {
                string res;
                while (n--) {
                    res += to_string(i % 2);
                    i /= 2;
                }
                reverse(res.begin(), res.end());
                return res;
            }
        }
        return "0";
    }

    int convert(string num, int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += (int)(num[i] - '0') * pow(2, n - i - 1);
        }
        return res;
    }
};

int main() {
    vector<string> nums = {"00","01"};
    Solution s;
    cout << s.findDifferentBinaryString(nums);
}
