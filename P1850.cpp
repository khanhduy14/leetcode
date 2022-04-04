//
// Created by PC on 4/3/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string pre = num;
        while (k--) {
            next_permutation(num.begin(), num.end());
        }
        int i = 0, j;
        int result = 0;

        while (i < num.size()) {
            j = i;
            while (pre[j] != num[i]) j++;

            while (i < j) {
                swap(pre[j], pre[j - 1]);
                j--;
                result++;
            }
            i++;
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.getMinSwaps("11112", 4);
}

// 21111