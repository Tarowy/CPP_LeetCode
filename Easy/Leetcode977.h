#include <vector>

using namespace std;

/**
977. 有序数组的平方
https://leetcode.cn/problems/squares-of-a-sorted-array/
 */
class Leetcode977 {
public:
    /**
     * nums是从大到小排列的，其中包含负数，负数的平方可能大于正数
     * 数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间
     * @param nums
     * @return
     */
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> result(nums.size(), 0);
        //result数组的索引
        int k = nums.size() - 1;

        //nums数组的左端指针
        int l = 0;
        //nums数组的右端指针
        int r = nums.size() - 1;

        while (l <= r) {
            int lSquare = nums[l] * nums[l];
            int rSquare = nums[r] * nums[r];

            //做指针
            if (lSquare > rSquare) {
                result[k--] = lSquare;
                l++;
                continue;
            }

            result[k--] = rSquare;
            r--;
        }

        return result;
    }
};
