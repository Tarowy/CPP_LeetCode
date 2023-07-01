//
// Created by Tarowy on 2023-05-31.
//
#include "vector"
#include "algorithm"
#include "iostream"
#include "list"

using namespace std;

/**
 * 406. 根据身高重建队列
 * https://leetcode.cn/problems/queue-reconstruction-by-height/
 */
class LeetCode406 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(),
             [](const vector<int> &p1, const vector<int> &p2) {
                 //按身高降序排列，再按比当前身高高的人数按升序排列
                 return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] > p2[0];
             });
        for_each(people.begin(), people.end(), [](const vector<int> &p) {
            cout << "[" << p[0] << ", " << p[1] << "]" << endl;
        });

        //[7,0][7,1][6,1][5,0][5,2][4,4]
        list<vector<int>> result;

        /**
         * 每次遍历的身高都是小于等于之前的元素的，而且将比它小的身高插入到它之前不会影响元素的第二个值代表的含义
         * 第二个元素代表有多少个元素比大于等于它的身高，所以插入的时候插入到元素对应的下标处即可
         */
        for (auto &person: people) {
            //依次按元素的第二个值将元素插入到结果集中
            int position = person[1];
            auto list_begin = result.begin();
            while (position--)
                list_begin++;
            result.insert(list_begin, person);
        }

        return {result.begin(), result.end()};
    }
};
