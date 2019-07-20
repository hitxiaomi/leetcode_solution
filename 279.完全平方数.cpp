/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (50.39%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 26.2K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */


#include <vector>
#include <math.h>
#include <queue>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        //因为题目要求完全平方数的个数最少，所以考虑采用广度优先算法去处理
        //定义返回值
        int res=0;
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        //找到所有可能的完全平方数
        int max_i=static_cast<int>(sqrt(n));
        vector<int> possible_nums;
        for(int i=max_i;i>0;i--){
            possible_nums.push_back(i*i);
        }
        //定义广度优先需要的队列
        queue<int> queue_int;
        //按照题意不需要定义visited

        //将n定义为根节点
        queue_int.push(n);

        while (!queue_int.empty()/* condition */)
        {
            int queue_size=queue_int.size();

            //处理第res层数据
            for(int i=0;i<queue_size;i++){
                //取出第一个元素
                int element_in_queue=queue_int.front();
                queue_int.pop();
                
                //首先判断是否找到目标
                if(element_in_queue==0) {
                    return res;
                }
                //将该元素的所有邻居加入队列
                for(int j=0;j<possible_nums.size();j++){
                    int temp_num=element_in_queue-possible_nums[j];
                    if(temp_num>=0){
                        queue_int.push(temp_num);

                    }
                }
                
                


            }
            res++;


            /* code */
        }
        return -1;
        



        

        


        
    }
};
// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(1, 0);
//         while (dp.size() <= n) {
//             int m = dp.size(), val = INT_MAX;
//             for (int i = 1; i * i <= m; ++i) {
//                 val = min(val, dp[m - i * i] + 1);
//             }
//             dp.push_back(val);
//         }
//         return dp.back();
//     }
// };

