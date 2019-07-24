/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 *
 * https://leetcode-cn.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (35.26%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 36.3K
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * 给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
 * 
 * 我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
 * 
 * 如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * nums = [1, 7, 3, 6, 5, 6]Easy
 * 输出: 3
 * 解释: 
 * 索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
 * 同时, 3 也是第一个符合要求的中心索引。
 * 
 * 
 * 示例 2:
 * 
 * 如果数组不存在中
 * 
 * 输入: 
 * nums = [1, 2, 3]
 * 输出: -1
 * 解释: 
 * 数组中不存在满足此条件的中心索引。
 * 
 * 说明:
 * 
 * 
 * nums 的长度范围为 [0, 10000]。
 * 任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        //如果存在这个索引的话，index 取值范围应该是{0, size_nums-2}

        int sum=0;
        for(auto const & num:nums){
            sum+=num;
        }   //计算得到数据的和
        // int target=sum/2;
        int size_of_nums=nums.size();
        int left_sum=0;

        for(int i=0;i<size_of_nums;i++){  //直接跳过了
            if(left_sum==sum-left_sum-nums[i]){
                return i;
            }
            left_sum+=nums[i];
        }

        return -1;





 

      


        
    }
};

