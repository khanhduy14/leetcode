#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int last[26];
        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }
        int end = 0, start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (end == i) {
                res.push_back(end - start + 1);
                start = end + 1;
                continue;
            }
            end = max(end, last[s[i] - 'a']);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> r = s.partitionLabels("eccbbbbdec");
    for (auto &x: r) {
        cout << x << endl;
    }
}