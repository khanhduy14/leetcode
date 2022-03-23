#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        vector<int> res;
        int cnt = 0, idx = 0;
        for (int num : nums) {
            if (num == target) ++cnt;
            if (num < target) ++idx;
        }

        while (cnt--) res.push_back(idx++);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 5, 2, 3};
    for (auto &r: s.targetIndices(a, 2)) {
        cout << r << endl;
    }
}