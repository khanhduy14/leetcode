//
// Created by PC on 4/3/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int m = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] >= m) {
                m = nums[i];
                for (int j = i; j < nums.size() - 1; ++j) {
                    swap(nums[j], nums[j + 1]);
                }
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    return;
                }
            }
        }
        sort(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> a = {2, 3, 1};
    Solution s;
    s.nextPermutation(a);
    for (auto &x: a) {
        cout << x << endl;
    }
}
