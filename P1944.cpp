#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> &a) {
        vector<int> res(a.size(), 0);
        stack<int> q;
        q.push(a[a.size() - 1]);
        for (int i = a.size() - 2; i >= 0; --i) {
            if (a[i] < a[i + 1]) {
                res[i] = 1;
                q.push(a[i]);
                continue;
            }
            int k = 0;
            while (!q.empty() && q.top() < a[i]) {
                k++;
                q.pop();
            }
            res[i] = q.empty() ? k : k + 1;
            q.push(a[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a = {3,1,5,8,6};
    for (auto &r: s.canSeePersonsCount(a)) {
        cout << r << endl;
    }
}