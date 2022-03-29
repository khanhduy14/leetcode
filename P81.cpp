#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool search(vector<int> &a, int target) {
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            int m = (r + l + 1) / 2;
            if (a[m] == target) return true;

            if (min(target, min(a[l], min(a[r], a[m]))) == target || max(target, max(a[l], max(a[r], a[m]))) == target) {
                for (int i = l; i <= r; ++i) {
                    if (a[i] == target) return true;
                }
            }
            if (a[m] > target) {
                if (a[l] > target) {
                    l = m + 1;
                    continue;
                }
                r = m - 1;
            } else {
                if (a[r] >= target) {
                    l = m + 1;
                    continue;
                }
                r = m - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 0, 1, 1, 1};
    cout << s.search(a, 0);
}