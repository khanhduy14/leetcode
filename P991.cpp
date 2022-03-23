#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while (target > startValue) {
            if (target % 2 != 0) {
                target++;
                ++res;
            }
            target /= 2;
            ++res;
        }
        return startValue - target + res;
    }
};

int main() {
    Solution s;
    cout << s.brokenCalc(3, 10);
}