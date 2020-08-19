/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (52.47%)
 * Likes:    378
 * Dislikes: 0
 * Total Accepted:    134.5K
 * Total Submissions: 256.3K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2,2]
 *
 *
 * 示例 2:
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[4,9]
 *
 *
 *
 * 说明：
 *
 *
 * 输出出结果中每个元素现的次数，应与元素在两个数组中出现次数的最小值一致。
 * 我们可以不考虑输出结果的顺序。
 *
 *
 * 进阶：
 *
 *
 * 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
 * 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 *
 *
 */

// @lc code=start

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 private:
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // assume nums1.size < nums2.size
    std::vector<int> result;
    if (nums1.size() > nums2.size()) {
      return intersect(nums2, nums1);
    }
    std::unordered_map<int, int> num_times_map;
    for (const int& num : nums1) {
      ++num_times_map[num];
    }

    for (const int& num : nums2) {
      if (num_times_map.count(num)) {
        result.push_back(num);
        num_times_map[num]--;
        if (num_times_map[num] == 0) {
          num_times_map.erase(num);
        }
      }
    }

    return result;
  }
};
// @lc code=end
