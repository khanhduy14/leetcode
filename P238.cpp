//
// Created by PC on 4/6/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> res(nums.size() + 1);
        res[nums.size()] = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = res[i + 1] * nums[i];
        }
        int t = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == nums.size() - 1) res[i] = t;
            res[i] = t * res[i + 1];
            t *= nums[i];
        }
        res.pop_back();
        return res;
    }
};

int main() {
    vector<int> n = {-1,1,0,-3,3};
    Solution s;
    for (auto &x: s.productExceptSelf(n)) {
        cout << x << endl;
    }
}
