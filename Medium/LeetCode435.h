//
// Created by Tarowy on 2023-06-12.
//

#ifndef LEETCODE_LEETCODE435_H
#define LEETCODE_LEETCODE435_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 435. 无重叠区间
 * https://leetcode.cn/problems/non-overlapping-intervals/
 */
class Solution {
public:
    int eraseOverlapIntervals(vector <vector<int>> &intervals) {
        //按X_start升序排序
        sort(intervals.begin(), intervals.end(), [](const vector<int> &p1, const vector<int> &p2) {
            if (p1[0] == p2[0])
                return p1[1] < p2[1];
            return p1[0] < p2[0];
        });

        //[[1,2],[1,3],[2,3],[3,4]]
        for_each(intervals.begin(), intervals.end(), [](const vector<int> &p1) {
            cout << "[" << p1[0] << ", " << p1[1] << "]";
        });
        cout << endl;

        int result = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                result++;
                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
            }
        }

        return result;
    }
};

#endif //LEETCODE_LEETCODE435_H
