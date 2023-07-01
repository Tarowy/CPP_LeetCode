//
// Created by Tarowy on 2023-05-01.
//
using namespace std;

#include "vector"
#include "algorithm"

/**
 * 455. 分发饼干
 * https://leetcode.cn/problems/assign-cookies/
 */
class LeetCode455 {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        if (g.empty() || s.empty())
            return 0;

        int result = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int sIndex = s.size() - 1;
        //选择胃口
        for (int i = g.size() - 1; i >= 0; --i) {
            //如果当前最大的饼干大于当前小孩的胃口，就将饼干分出去
            if (s[sIndex] >= g[i]) {
                result++;
                sIndex--;
            }
            if (sIndex < 0)
                break;
        }

        return result;
    }
};
