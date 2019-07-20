/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (38.83%)
 * Likes:    910
 * Dislikes: 0
 * Total Accepted:    93.6K
 * Total Submissions: 240.9K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;

        }
        int size_string=s.size();
        stack<char> stack_char;
        for(int i=0;i<size_string;i++){
            //step 1  判断当前字符 是否为 ‘（’ ‘【’  ‘’
            if(s[i]=='(' || s[i]=='['|| s[i]=='{'){
                stack_char.push(s[i]);
            }
            else { //为右括号
                if(stack_char.empty())//首先栈中必须是有元素的
                    return false;
                switch ( s[i] )
                {
                case  ')'/* constant-expression */:
                    {if(stack_char.top() != '(' ) {/* code */
                        return false;                    
                    }
                    else{
                        stack_char.pop();
                    }
                    break;}
                case  ']'/* constant-expression */:
                    {if(stack_char.top() != '[' ) {/* code */
                        return false;                    
                    }
                    else{
                        stack_char.pop();
                    }
                    break;}


                 case  '}'/* constant-expression */:
                    {if(stack_char.top() != '{' ) {/* code */
                        return false;                    
                    }
                    else{
                        stack_char.pop();
                    }
                    
                    break;}  

                
                default:
                    break;
                }

            }
            
        }
        if(stack_char.empty())
            return true;
        else
            return false;
        
        

        
    }
};

