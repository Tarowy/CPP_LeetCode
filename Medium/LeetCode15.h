//
// Created by Tarowy on 2023-03-15.
//
using namespace std;

#include <vector>
#include <algorithm>

/**
 * 15. 三数之和
 * https://leetcode.cn/problems/3sum/
 */
class LeetCode15 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector <vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            //如果第一个元素大于0，那么后两个元素不可能相加再等于负数来让总和为0
            if (nums[i] > 0)
                return result;

            //对第一个元素进行去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                //总和大于目标值，则需要缩减右指针使总和缩小
                if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                    //总和小于目标值，则需要扩大右指针使总和扩大
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else {
                    //总和等于目标值，则将其加入到结果集中
                    result.push_back({nums[i], nums[left], nums[right]});
                    //对left和right索引进行去重
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    //指针收缩防止重复计算当前索引的值
                    left++;
                    right--;
                }

            }
        }
        return result;
    }
};
