//
// Created by PC on 4/2/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void euler(unordered_map<int, stack<int>> &adj, vector<vector<int>> &ans, int curr) {
        auto &stk = adj[curr];
        while (!stk.empty()) {
            int nei = stk.top();
            stk.pop();
            euler(adj, ans, nei);
            // postorder
            ans.push_back({curr, nei});
        }
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
        unordered_map<int, stack<int>> g;
        unordered_map<int, int> countI;
        unordered_map<int, int> countO;
        vector<vector<int>> res;
        for (auto &x: pairs) {
            g[x[0]].push(x[1]);
            countO[x[0]]++;
            countI[x[1]]++;
        }

        int s = -1;
        for (auto &p: g) {
            if ((countO[p.first] - countI[p.first]) == 1) s = p.first;
        }

        if (s == -1) {
            for (auto &p: g) {
                s = p.first;
                break;
            }
        }

        euler(g, res, s);
        reverse(res.begin(), res.end());
        return res;
    }
};


// 1 3 / 2 1 / 1 2

int main() {
    vector<vector<int>> p = {{1, 2},
                             {1, 3},
                             {2, 1}};
    Solution s;
    for (auto &x: s.validArrangement(p)) {
        cout << x[0] << " " << x[1] << endl;
    }
}