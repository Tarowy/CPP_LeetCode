//
// Created by Tarowy on 2023-03-14.
//
using namespace std;

#include <vector>
#include <unordered_map>

class LeetCode1 {
    vector<int> twoSum(vector<int> &nums, int target) {
        //key无序，所以存取的效率很高
        unordered_map<int, int> result_map;

        for (int i = 0; i < nums.size(); i++) {
            //查找有没有能和当前索引下的数值相加为target的数值
            auto iter = result_map.find(target - nums[i]);

            if (iter != result_map.end())
                return {iter->second, i};

            result_map.insert(pair<int,int>(nums[i],i));
        }

        return {};
    }
};
