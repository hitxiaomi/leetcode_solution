/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 *
 * https://leetcode-cn.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (38.30%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    4.7K
 * Total Submissions: 12.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 输出:  [1,2,4,7,5,3,6,8,9]
 * 
 * 解释:
 * 
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 给定矩阵中的元素总数不会超过 100000 。
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        if(matrix.empty())
            return vector<int>();
        if(matrix[0].empty())
            return vector<int>();
        int rows=matrix.size();
        int colums=matrix[0].size();
        int size_of_result=rows*colums;

        vector<int > result(size_of_result,0);
        int dir[2][2]={{-1,1},{1,-1}};
        int r=0,c=0,k=0;
        for(int i=0;i<size_of_result;i++){
            result[i]=matrix[r][c];

            int tem_r=r+dir[k][0],tem_c=c+dir[k][1];
            if(tem_r>=0&&tem_r<rows && tem_c>=0&&tem_c<colums){
                r=tem_r;
                c=tem_c;
            }
            else {
                k=1-k;
                if(k==1){
                    if(c<colums-1){
                        r=r;
                        c=c+1;
                    }
                    else {
                        c=c;
                        r=r+1;
                    }

                }
                else {
                    if(r<rows-1){
                        c=c;
                        r=r+1;
                    }
                    else {
                        r=r;
                        c=c+1;
                    }
                    

                }



            }
            

        }
    return result;


        
    }
};

