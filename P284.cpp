//
// Created by PC on 4/25/2022.
// https://leetcode.com/problems/peeking-iterator/

#include "bits/stdc++.h"

using namespace std;

class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
    }

    int peek()
    {
        return Iterator(*this).next();
    }

    int next()
    {
        return Iterator::next();
    }

    bool hasNext() const
    {
        return Iterator::hasNext();
    }
};