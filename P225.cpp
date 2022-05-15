//
// Created by Duy DA. Kieu Khanh on 05/05/2022.
// https://leetcode.com/problems/implement-stack-using-queues/

#include "bits/stdc++.h"

using namespace std;

class MyStack {
public:
    vector<int> v;
    MyStack() {

    }

    void push(int x) {
        v.push_back(x);
    }

    int pop() {
        int x = v.back();
        v.pop_back();
        return x;
    }

    int top() {
        return v.back();
    }

    bool empty() {
        return v.empty();
    }
};
