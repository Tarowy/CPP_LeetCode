//
// Created by Tarowy on 2023-03-13.
//

#include <string>
#include <array>
#include <algorithm>

using namespace std;

/**
 * 242. 有效的字母异位词
 * https://leetcode.cn/problems/valid-anagram/
 */
class LeetCode242 {
public:
    bool isAnagram(string s, string t) {
        //将26个字母映射到26个索引的int数组
        array<int, 26> table = {0};

        for (char &c: s)
            table[c - 'a']++;
        for (char &c: t)
            table[c - 'a']--;

        return all_of(table.begin(), table.end(),[](int i) { return i != 0; });
    }
};
