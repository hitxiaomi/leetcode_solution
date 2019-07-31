/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (36.55%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 49.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty())
            return vector<int >();
        int rows=matrix.size(),colums=matrix[0].size();
        int r=0,c=0,k=0;
        int min_row=0,max_row=rows-1;
        int min_colum=0,max_colum=colums-1;
        int size_result=rows*colums;
        vector<int > result(size_result,0);
        for(int i=0;i<size_result;i++){
            result[i]=matrix[r][c];
            switch (k)
            {
            case 0:{
                int tem_c=c+1;
                if(tem_c<=max_colum)
                    c=tem_c;
                else {
                    c=c;
                    r=r+1;
                    k=1;
                    min_row++;
                    
                }
                break;
            }
            case 1:{
                int tem_r=r+1;
                if(tem_r<=max_row)
                    r=tem_r;
                else {
                    r=r;
                    c=c-1;
                    k=2;
                    max_colum--;
                }
                
                break;
            }
            case 2:{
                int tem_c=c-1;
                if(tem_c>=min_colum){
                    c=tem_c;
                    
                }
                else {
                    c=c;
                    r=r-1;
                    k=3;
                    max_row--;
                }
                break;



            }
            case 3:{
                int tem_r=r-1;
                if(tem_r>=min_row)
                    r=tem_r;
                else{
                    r=r;
                    c=c+1;
                    k=0;
                    min_colum++;                  


                }
                break;
            }
                
            
            default:
                break;
            }


        } 
    return result;
        
    }
};

