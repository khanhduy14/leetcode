//
// Created by PC on 4/24/2022.
// https://leetcode.com/problems/design-underground-system/

#include "bits/stdc++.h"

using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, double>> in_m;
    unordered_map<string, pair<double, double>> avg;
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        in_m[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        pair<string, int> in = in_m[id];
        string key = in.first + "+" + stationName;
        if (avg.count(key)) {
            pair<int, int> curr = avg[key];
            avg[key] = {curr.first + t - in.second, curr.second + 1};
        } else {
            avg[key] = {t - in.second, 1};
        }
    }

    double getAverageTime(string startStation, string endStation) {
        return avg[startStation + "+" + endStation].first / avg[startStation + "+" + endStation].second;
    }
};
