#include <vector>

using namespace std;

/**
 * 209. 长度最小的子数组
 * https://leetcode.cn/problems/minimum-size-subarray-sum/
 */
class LeetCode209 {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int sum = 0;
        //如果一次都没进入下面WHILE循环，说明整个数组加起来都不满足条件，结果就是0
        int minLength = 0;
        //窗口的左端和右端
        int l = 0, r = 0;

        //依次移动右端来扩大窗口
        for (r = 0; r < nums.size(); ++r) {
            sum += nums[r];

            while (sum >= target) {
                //选出最小的窗口长度,
                //如果长度为0则说明是第一次执行该语句，为其计算长度
                minLength = minLength == 0 ? r - l + 1 : min(r - l + 1, minLength);
                //依次移动左端来缩小窗口
                sum -= nums[l];
                l++;
            }
        }

        return  minLength;
    }
};
