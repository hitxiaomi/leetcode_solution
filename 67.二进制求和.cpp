/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (49.60%)
 * Likes:    224
 * Dislikes: 0
 * Total Accepted:    32.4K
 * Total Submissions: 65.3K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int a_size=a.size();
        int b_size=b.size();
        string res;
        if(a_size>b_size)
            res.resize(a_size);
        else 
            res.resize(b_size);
        int i=a_size-1,j=b_size-1,k=res.size()-1;
        int carried=0;
        while (i>=0&&j>=0){
            int num_sum= a[i]-'0'+b[j]-'0'+carried;
            res[k]=(num_sum%2) +'0';
            carried =num_sum/2;
            i--;
            j--; 
            k--;          

        }
        if(i<0&&j>=0){
            while (j>=0){
        
            int num_sum= b[j]-'0'+carried;
            res[k]=(num_sum%2) +'0';
            carried =num_sum/2;
            j--; 
            k--;

            }
        }
        else if(j<0 &&i>=0){
            while (i>=0){
            int num_sum= a[i]-'0'+carried;
            res[k]=(num_sum%2) +'0';
            carried =num_sum/2;
            i--;
            k--;
            }
           
        }

        if(carried==1){
            res.insert(0,"1");
        }

        return res;     
                       
    }

    
};

