//
// Created by Tarowy on 2023-03-14.
//
using namespace std;

#include <vector>
#include <unordered_map>

/**
 * 454. 四数相加 II
 * https://leetcode.cn/problems/4sum-ii/
 */
class LeetCode454 {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> result_map;

        //将所有 nums1和nums2中的元素两两相加的结果 增加其在map中对应的次数
        for (int num1: nums1) {
            for (int num2: nums2) {
                result_map[num1 + num2]++;
            }
        }

        int count = 0;
        //从result_map中查找能和 nums3和nums4两两相加的结果 等于0的 数值对应的次数
        for (int num3: nums3) {
            for (int num4: nums4) {
                if (result_map.find(0 - (num3 + num4)) != result_map.end()) {
                    count += result_map[0 - (num3 + num4)];
                }
            }
        }

        return count;
    }
};
