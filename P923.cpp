//Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
//
//As the answer can be very large, return it modulo 109 + 7.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int> &A, int target) {
        unordered_map<int, long> c;
        for (int a: A) c[a]++;
        long res = 0;
        for (auto it: c)
            for (auto it2: c) {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!c.count(k)) continue;
                if (i == j && j == k)
                    res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                else if (i == j && j != k)
                    res += c[i] * (c[i] - 1) / 2 * c[k];
                else if (i < j && j < k)
                    res += c[i] * c[j] * c[k];
            }
        return res % int(1e9 + 7);
    }
};

int main() {
    vector<int> a = {1, 1, 2, 2, 2, 2};
    Solution s;
    cout << s.threeSumMulti(a, 5);
}