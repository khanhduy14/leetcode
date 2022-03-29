//
// Created by PC on 3/29/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        if (nums.size() > 1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a = {2, 2, 2, 2, 2};
    cout << s.findDuplicate(a);
}
