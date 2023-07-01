//
// Created by Tarowy on 2023-06-30.
//

#ifndef LEETCODE_LEETCODE56_H
#define LEETCODE_LEETCODE56_H

#include<string>
#include<algorithm>
#include<vector>

using namespace std;

/**
 * 56. 合并区间
 * https://leetcode.cn/problems/merge-intervals/
 */
class Solution {
public:
    vector <vector<int>> merge1(vector <vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &p1, const vector<int> &p2) {
            return p1[0] < p2[0];
        });

        vector <vector<int>> result;

        //intervals = [[1,3],[2,6],[8,10],[15,18]]
        //intervals = [[1,4],[2,3]]
        for (int i = 1; i < intervals.size(); ++i) {
            //如果当前区间的左端点小于前一个区间的右端点，则延长当前区间的左端点至前一个区间的左端点
            if (intervals[i][0] <= intervals[i - 1][1]) {
                intervals[i][0] = intervals[i - 1][0];

                //当前区间的右端点小于前一个区间的右端点，则需要延长当前区间的右端点至前一个区间的右端点
                if (intervals[i][1] < intervals[i - 1][1])
                    intervals[i][1] = intervals[i - 1][1];
            }
                //否则当前区间与前一个区间不重叠，将前一个区间加入到结果集
            else {
                result.emplace_back(intervals[i - 1]);
            }
        }
        result.emplace_back(intervals[intervals.size() - 1]);

        return result;
    }

    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &p1, const vector<int> &p2) {
            return p1[0] < p2[0];
        });

        vector <vector<int>> result;

        //intervals = [[1,3],[2,6],[8,10],[15,18]]
        //intervals = [[1,4],[2,3]]
        result.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            //当前区间的左端点 小于 最后已加入到结果集区间的右端点，则更新结果集的右区间
            if (intervals[i][0] <= result.back()[1]) {
                //不能盲目更新，因为是求并集，所以需要确保右端点不会被缩小
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
                //否则 当前区间 与 最后已加入到结果集区间 不重叠，将该区间直接加入到结果集
            else {
                result.emplace_back(intervals[i]);
            }
        }

        return result;
    }
};

#endif //LEETCODE_LEETCODE56_H
