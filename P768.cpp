//
// Created by PC on 5/15/2022.
// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        stack<pair<int, int>> s;
        for (int x: arr) {
            if (!s.empty() && x < s.top().second) {
                int ma = INT_MIN;
                int mi = INT_MAX;
                while (!s.empty() && x < s.top().first) {
                    ma = max(s.top().first, ma);
                    mi = min(s.top().second, mi);
                    s.pop();
                }
                if (s.empty() || x >= s.top().first) s.push({ma, min(x, mi)});
            } else if (s.empty() || x >= s.top().first) {
                s.push({x, x});
            }
        }

        return s.size();
    }
};

int main() {
    Solution s;
    vector<int> arr = {2,1,3,4,4};
    cout << s.maxChunksToSorted(arr);
}
