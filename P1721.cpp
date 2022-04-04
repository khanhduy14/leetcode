//
// Created by PC on 4/4/2022.
//

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *right;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *f;
        ListNode *s = nullptr;
        for (auto p = head; p != nullptr; p = p->next) {
            s = s == nullptr ? nullptr : s->next;
            if (--k == 0) {
                f = p;
                s = head;
            }
        }
        if (s && f) {
            swap(s->val, f->val);
        }
        return head;
    }
};

int main() {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    vector<int> i = {100, 90};
    for (auto a: i) {
        auto x = new ListNode;
        x->val = a;
        ListNode *&node = x;

        tail = tail->next = node;
    }
    Solution s;
    ListNode *r = s.swapNodes(dummy.next, 5);

    while (r) {
        cout << r->val << endl;
        r = r->next;
    }
}