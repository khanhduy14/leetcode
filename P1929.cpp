#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 1};
    for (auto &r: s.getConcatenation(a)) {
        cout << r << endl;
    }
}