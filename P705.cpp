//
// Created by PC on 4/21/2022.
// https://leetcode.com/problems/design-hashset/

#include <bits/stdc++.h>

using namespace std;

class MyHashSet {
public:
    unordered_map<int, bool> m;
    MyHashSet() {

    }

    void add(int key) {
        m[key] = true;
    }

    void remove(int key) {
        if (m[key]) m[key] = false;
    }

    bool contains(int key) {
        return m[key];
    }
};

