/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (40.81%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    5.9K
 * Total Submissions: 14.3K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 * 
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums: [1, 1, 1, 1, 1], S: 3
 * 输出: 5
 * 解释: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * 一共有5种方法让最终目标和为3。
 * 
 * 
 * 注意:
 * 
 * 
 * 数组的长度不会超过20，并且数组中的值全为正数。
 * 初始的数组的和不会超过1000。
 * 保证返回的最终结果为32位整数。
 * 
 * 
 *///这个解法超时，需要优化
#include<vector>
using namespace std;
class Solution {
private:
    int count_=0;//结果个数
    int size_of_nums_;
    int DFS(const vector<int > &nums,int i,int s){
        //终止条件是
        if(i>size_of_nums_-1){
            //数组遍历完
            if(s==0)
             count_++;
            return true;            

        }

        DFS(nums,i+1,s+nums[i]);
        DFS(nums,i+1,s-nums[i]);
        
        return true;

    }
    

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        size_of_nums_=nums.size();
        int sum=0;
        // for(auto const & num:nums){
        //     sum+=num;
        // }
        // if(S>sum||S<-sum)
        // return 0;
        
        DFS(nums,0,S);//
        
        return count_;
        
    }
};

