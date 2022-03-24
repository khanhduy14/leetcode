#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int> &a, int limit) {
        sort(a.begin(), a.end());
        int res = 0;
        int j = a.size() - 1;
        int i = 0;
        while (i <= j) {
            res++;
            if ((a[j] + a[i]) <= limit) i++;
            --j;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a = {2, 49, 10, 7, 11, 41, 47, 2, 22, 6, 13, 12, 33, 18, 10, 26, 2, 6, 50, 10};
    cout << s.numRescueBoats(a, 50);

}