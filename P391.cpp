//
// Created by PC on 4/4/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>> &A) {
        long area = 0;
        unordered_map<string, int> m;
        int xm = 1e5 + 1, ym = 1e5 + 1, am = -xm, bm = -ym;

        for (int i = 0; i < A.size(); ++i) {
            area += (long) (A[i][2] - A[i][0]) * (A[i][3] - A[i][1]);
            xm = min(A[i][0], xm);
            ym = min(A[i][1], ym);
            am = max(A[i][2], am);
            bm = max(A[i][3], bm);

            if (m[to_string(A[i][0]) + " " + to_string(A[i][1])])
                m.erase(to_string(A[i][0]) + " " + to_string(A[i][1]));
            else m[to_string(A[i][0]) + " " + to_string(A[i][1])]++;
            if (m[to_string(A[i][0]) + " " + to_string(A[i][3])])
                m.erase(to_string(A[i][0]) + " " + to_string(A[i][3]));
            else m[to_string(A[i][0]) + " " + to_string(A[i][3])]++;
            if (m[to_string(A[i][2]) + " " + to_string(A[i][1])])
                m.erase(to_string(A[i][2]) + " " + to_string(A[i][1]));
            else m[to_string(A[i][2]) + " " + to_string(A[i][1])]++;
            if (m[to_string(A[i][2]) + " " + to_string(A[i][3])])
                m.erase(to_string(A[i][2]) + " " + to_string(A[i][3]));
            else m[to_string(A[i][2]) + " " + to_string(A[i][3])]++;
        }

        if (!m[to_string(xm) + " " + to_string(ym)] ||
            !m[to_string(am) + " " + to_string(ym)] ||
            !m[to_string(xm) + " " + to_string(bm)] ||
            !m[to_string(am) + " " + to_string(bm)] || m.size() != 4) {
            return false;
        }
        return area == (long)(am - xm) * (bm - ym);
    }
};


int main() {
    vector<vector<int>> r = {{1,1,3,3},
                             {3,1,4,2},
                             {3,2,4,4},
                             {1,3,2,4}, {2,3,3,4}};
    Solution s;
    cout << s.isRectangleCover(r);
}
