#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int> &nums, int k) {
        if (nums.size() % k != 0) return false;
        int mi = 1e9 + 1, ma = 0;
        unordered_map<int, int> m;
        for (int &num: nums) {
            m[num]++;
            mi = min(mi, num);
            ma = max(ma, num);
        }
        int t = 0;
        for (int i = mi; i <= ma - k + 1; ++i) {
            while (m[i] > 0) {
                for (int j = 0; j < k; ++j) {
                    m[i + j]--;
                    ++t;
                    if (m[i + j] < 0) return false;
                }
            }
        }
        return t == nums.size();
    }
};

int main() {
    Solution s;
    vector<int> input = {1, 1, 2, 2, 3, 3};
    cout << s.isPossibleDivide(input, 2);
}