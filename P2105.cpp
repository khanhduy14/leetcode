//
// Created by PC on 4/6/2022.
// https://leetcode.com/problems/watering-plants-ii/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int> &plants, int A, int B) {
        int res = 0;
        int ma = A, mb = B;
        int l = 0, r = plants.size() - 1;
        while (l <= r) {
            if (l == r && plants[l] > max(A, B)) {
                res++;
            }

            if (l < r) {
                if (A >= plants[l]) A -= plants[l];
                else {
                    res++;
                    A = ma - plants[l];
                }

                if (B >= plants[r]) B -= plants[r];
                else {
                    res++;
                    B = mb - plants[r];
                }
            }
            l++;
            r--;
        }
        return res;
    }
};

int main() {
    vector<int> p = {5};
    Solution s;
    cout << s.minimumRefill(p, 4, 6);
}
