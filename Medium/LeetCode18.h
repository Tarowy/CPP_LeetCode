//
// Created by Tarowy on 2023-03-16.
//
#include "vector"
#include "algorithm"

using namespace std;

/**
 * 18. 四数之和
 * https://leetcode.cn/problems/4sum/
 */
class LeetCode18 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        //如果两个负数相加，结果反而会更小
        for (int i = 0; i < nums.size(); ++i) {
            //第一个数大于0，那么后面的数一定也都大于0，如果第一个数还比target大，那么四数相加绝对不可能等于target
            if (nums[i] >= 0 && nums[i] > target)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size(); ++j) {
                //前两个数的和大于0的前提下，如果和还大于target，后面的数一定也大于0，其相加的结果必定不会等于target
                if (nums[i] + nums[j] >= 0 && nums[i] + nums[j] > target)
                    break;

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    //缩小四数相加的和
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                        right--;
                        //增大四数相加的和
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                        left++;
                    else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
