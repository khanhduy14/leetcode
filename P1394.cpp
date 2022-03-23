#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLucky(vector<int> &arr) {
        unordered_map<int, int> m;
        for (auto &num: arr) {
            m[num]++;
        }
        int res = -1;
        for (auto &p: m) {
            if (p.first == p.second) res = max(p.first, res);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> input = {1, 2, 2, 3, 3, 3};
    cout << s.findLucky(input);
}