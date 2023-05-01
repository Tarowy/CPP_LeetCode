//
// Created by Tarowy on 2023-03-30.
//
using namespace std;

#include "vector"
#include "queue"
#include "unordered_map"

/**
 * 347. 前 K 个高频元素
 * https://leetcode.cn/problems/top-k-frequent-elements/
 */
class LeetCode347 {
    //用以实现小根堆队列
    class my_comparison {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> statisticsMap;
        for (int i = 0; i < nums.size(); i++)
            statisticsMap[nums[i]]++;

        //小根堆
        priority_queue < pair < int, int >, vector < pair < int, int >>, my_comparison > pri_que;

        for (auto & it : statisticsMap) {
            pri_que.push(it);
            //如果根堆中的元素数量大于k，则将最小的元素弹出，最后会剩余出现频率最高的两个元素
            if (pri_que.size() > k)
                pri_que.pop();
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
