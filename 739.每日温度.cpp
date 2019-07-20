/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (58.50%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    7.7K
 * Total Submissions: 13.2K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector< int>  dailyTemperatures( vector<int>& T ) {
        int size_T=T.size();
        //构建返回值
        vector<int > result(size_T,0);
        //定义一个栈，保存已经访问的元素，
        stack <int> stack_int;


        //数组遍历 ,从后往前遍历，方便求解,每次遍历需要对result对应位置赋top
        for(int i=size_T-1;i>=0;i--){
            //step 1 判断当前元素跟栈top 元素的大小关系，如果栈top的小于或者等于比当前元素，那就一直pop就可以了，
            //直到当前元素小于栈top
            while( !stack_int.empty() && T[i]>= T[stack_int.top()])  {
                stack_int.pop();
            }
            //
            //step2  对result赋值 对堆栈进行更新，将当前值也要进栈
            //对result[i]
            if(!stack_int.empty()){
                result[i]=stack_int.top()-i;
            }

            stack_int.push(i);

        }
        return result;



        
    }
};

