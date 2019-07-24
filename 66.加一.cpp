/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.78%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    63.3K
 * Total Submissions: 159.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;//进位
        int size_of_digits=digits.size();
        
        for (int i=size_of_digits-1;i>-1;i--){
            int tem_num=digits[i]+carry;
            digits[i]=(tem_num)%10;
            carry=tem_num/10;              
            if(!carry) break;
                 
        }
        if(carry)
            digits.insert(digits.begin(),carry);

        return digits;
        
    }
};

