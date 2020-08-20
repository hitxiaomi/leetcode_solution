/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (38.64%)
 * Likes:    1224
 * Dislikes: 0
 * Total Accepted:    339K
 * Total Submissions: 877.1K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * 示例 1:
 *
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 *
 *
 * 示例 2:
 *
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 *
 *
 * 说明:
 *
 * 所有输入只包含小写字母 a-z 。
 *
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() < 1) return "";

    const std::string& first_string = strs[0];
    size_t first_string_size = first_string.size();


    for (size_t j = 0; j < first_string_size; j++) {

      for (size_t i = 1; i < strs.size(); i++) {
        if (strs[i][j] != first_string[j]) return first_string.substr(0, j);
      }

    }
    return first_string;
  }
};
// @lc code=end
