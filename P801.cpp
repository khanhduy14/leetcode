//
// Created by PC on 3/29/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwap(vector<int> &A, vector<int> &B) {
        int N = A.size();
        int not_swap[100001] = {0};
        int swap[100001] = {1};
        for (int i = 1; i < N; ++i) {
            not_swap[i] = swap[i] = N;
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                swap[i] = swap[i - 1] + 1;
                not_swap[i] = not_swap[i - 1];
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                swap[i] = min(swap[i], not_swap[i - 1] + 1);
                not_swap[i] = min(not_swap[i], swap[i - 1]);
            }
        }
        return min(swap[N - 1], not_swap[N - 1]);
    }
};

int main() {
    Solution s;
    vector<int> a1 = {1, 3, 5, 4};
    vector<int> a2 = {1, 2, 3, 7};
    cout << s.minSwap(a1, a2);
}