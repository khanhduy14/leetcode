//
// Created by PC on 4/30/2022.
// https://leetcode.com/problems/next-greater-node-in-linked-list/

#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        stack<int> s;
        vector<int> r;
        while (head != nullptr) {
            while (!s.empty() && r[s.top()] < head->val) {
                int f = s.top();
                s.pop();
                r[f] = head->val;
            }
            if (head->next == nullptr) {
                r.push_back(0);
                break;
            }
            r.push_back(head->val);
            s.push(r.size() - 1);
            head = head->next;
        }

        while (!s.empty()) {
            r[s.top()] = 0;
            s.pop();
        }

        return r;
    }
};
