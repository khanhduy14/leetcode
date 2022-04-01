//
// Created by PC on 4/1/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> r;
    unordered_map<string, int> m;
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        for (auto &st: wordDict) {
            m[st]++;
        }

        getS("", s);
        return r;
    }

    void getS(string res, string s) {
        for (int i = 0; i < s.size(); ++i) {
            string temp = res;
            if (m[s.substr(0, i + 1)]) {
                if (i == (s.size() - 1)) {
                    temp += s.substr(0, i + 1);
                    r.push_back(temp);
                }
                else {
                    temp += s.substr(0, i + 1) + " ";
                    getS(temp, s.substr(i + 1));
                }
            }
        }
    }
};

int main() {
    vector<string> a = {"apple","pen","applepen","pine","pineapple"};
    Solution s;
    for (auto &x: s.wordBreak("pineapplepenapple", a)) {
        cout << x << endl;
    }
}