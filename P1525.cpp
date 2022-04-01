//
// Created by PC on 3/30/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSplits(string s) {
        set<char> st;
        set<char> st2;
        int ct[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            st.insert(s[i]);
            ct[s[i] - 'a']++;
        }

        int res = 0;

        for (int i = 0; i < s.size(); ++i) {
            st2.insert(s[i]);
            ct[s[i] - 'a']--;
            if (ct[s[i] - 'a'] == 0) st.erase(s[i]);

            if (st.size() == st2.size()) res++;
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.numSplits("abcd");
}
