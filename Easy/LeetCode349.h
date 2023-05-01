#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 349. 两个数组的交集
 * https://leetcode.cn/problems/intersection-of-two-arrays/
 */
class LeetCode349 {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());

        for (int num: nums2) {
            //如果能从result_set中查找到该元素，则将其加入结果集中
            if (nums_set.find(num) != nums_set.end())
                result_set.insert(num);
        }

        return vector<int>(result_set.begin(), result_set.end());
    }
};