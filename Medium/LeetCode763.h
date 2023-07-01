//
// Created by Tarowy on 2023-06-21.
//

#ifndef LEETCODE_LEETCODE763_H
#define LEETCODE_LEETCODE763_H

#include<string>
#include<algorithm>
#include<vector>

using namespace std;

/**
 * 763. 划分字母区间
 * https://leetcode.cn/problems/partition-labels/
 */
class Solution {
public:
    vector<int> partitionLabels(string s) {
        //记录每个字母出现的最远距离
        int furthestPos[27];
        for (int i = 0; i < s.size(); ++i)
            furthestPos[s[i] - 'a'] = i;

        //s = "ababcbaca defegde hijhklij"
        //     858575878
        vector<int> result;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); ++i) {
            //right是区间内所有字母出现的最远位置的最大值
            right = max(right, furthestPos[s[i] - 'a']);
            if (i == right) {
                result.emplace_back(right - left + 1);
                left = i + 1;
            }
        }

        return result;
    }
};

#endif //LEETCODE_LEETCODE763_H