//
// Created by PC on 5/8/2022.
// https://leetcode.com/problems/flatten-nested-list-iterator/

#include "bits/stdc++.h"

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    vector<int> v;
    int curr = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (NestedInteger nestedInteger: nestedList) {
            parseNested(nestedInteger);
        }

    }

    void parseNested(NestedInteger &nestedInteger) {
        if (nestedInteger.isInteger()) {
            v.push_back(nestedInteger.getInteger());
        } else {
            for (NestedInteger integer: nestedInteger.getList()) {
                parseNested(integer);
            }
        }
    }

    int next() {
        return v[curr++];
    }

    bool hasNext() {
        return curr < (v.size());
    }
};

