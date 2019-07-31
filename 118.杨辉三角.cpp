/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (63.21%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    30.3K
 * Total Submissions: 47.9K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int> > result(numRows,vector<int>());
         if(numRows==0)
            return result;
        
        result[0].push_back(1);

        for(int i=1;i<numRows;i++){
            result[i].push_back(1);
            int size_last_row = result[i-1].size();
            for (int j=1;j<size_last_row;j++){
                result[i].push_back(result[i-1][j] +result[i-1][j-1]);
                
            } 
            result[i].push_back(1);          

        }

    return result;


            
        
    }
};

