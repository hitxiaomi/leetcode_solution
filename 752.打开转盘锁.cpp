/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 *
 * https://leetcode-cn.com/problems/open-the-lock/description/
 *
 * algorithms
 * Medium (47.94%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 7.4K
 * Testcase Example:  '["0201","0101","0102","1212","2002"]\n"0202"'
 *
 * 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8',
 * '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
 * 
 * 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
 * 
 * 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
 * 
 * 字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * 输出：6
 * 解释：
 * 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
 * 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
 * 因为当拨动到 "0102" 时这个锁就会被锁定。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: deadends = ["8888"], target = "0009"
 * 输出：1
 * 解释：
 * 把最后一位反向旋转一次即可 "0000" -> "0009"。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
 * target = "8888"
 * 输出：-1
 * 解释：
 * 无法旋转到目标数字且不被锁定。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: deadends = ["0000"], target = "8888"
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 死亡列表 deadends 的长度范围为 [1, 500]。
 * 目标数字 target 不会在 deadends 之中。
 * 每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
 * 
 * 
 */
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;



class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int res=0; //结果
        const string begin_str="0000";
        queue<string> queue_str; //定义一个队列，用于广度优先搜索
        unordered_set<string > visited;//定义unordered set 用于记录是否元素是否已经被访问
        unordered_set<string > deadends_set;  //死锁 方便查看状态是否满足
        for(int i=0;i<deadends.size();i++){
            deadends_set.insert(deadends[i]);
        }
        if(deadends_set.find(begin_str)==deadends_set.end()){ //初始值不在deadends中才可以加入到队列中
            queue_str.push(begin_str);
            visited.insert(begin_str);

        }


        while (!queue_str.empty()/* condition */)
        {

            int queue_size=queue_str.size();
            for(int i=0;i<queue_size;i++) {

                string queue_front_str = queue_str.front();  //访问队列第一个元素
                if (queue_front_str.compare(target) == 0) {    //跟目标做比较
                    return res;
                }

                //将其关联的所有状态加入到队列中
                for (int i = 0; i < 4; i++) {//四个字符，每次更改一个字符
                    string tem_str1 = queue_front_str;  //用于增加
                    // if (tem_str1[i] == '9') {
                    //     tem_str1[i] = '0';
                    // } else {
                    //     tem_str1[i] += 1;
                    // }
                    tem_str1[i]=(tem_str1[i]-'0'+1)%10+'0';

                    if (deadends_set.find(tem_str1) == deadends_set.end() && visited.find(tem_str1) == visited.end()) {
                        queue_str.push(tem_str1);
                        visited.insert(tem_str1);
                    }

                    string tem_str2 = queue_front_str;  //用于减小
                    // if (tem_str2[i] == '0') {
                    //     tem_str2[i] = '9';
                    // } else {
                    //     tem_str2[i] -= 1;
                    // }
                    tem_str2[i]= '9'-('9'-tem_str2[i]+1)%10;

                    if (deadends_set.find(tem_str2) == deadends_set.end() && visited.find(tem_str2) == visited.end()) {
                        queue_str.push(tem_str2);
                        visited.insert(tem_str2);
                    }


                }

                queue_str.pop();

            }



            res++;







            /* code */
        }

        return -1;


    }
};


