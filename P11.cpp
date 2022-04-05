//
// Created by PC on 4/5/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& a) {
        int i = 0, j = a.size() - 1;
        int area = min(a[i], a[j]) * j;
        while (i < j) {
            if (a[i] >= a[j]) {
                --j;
            } else {
                ++i;
            }

            area = max(area, min(a[i], a[j]) * (j - i));
        }
        return area;
    }
};

int main() {

}