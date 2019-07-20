/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <vector>
#include <utility>
#include <queue>
using namespace std;

//使用广度优先或者深度优先搜索两种方法


//岛屿数量的广度优先解法

/*
class Solution {
private:
    bool pushDataToQueue(const vector<vector<char> >& grid,vector<vector<bool> >& visited, queue<pair<int ,int> > &qp ,int rows,int colums,int x,int y){
        if(x<0||x>rows-1||y<0||y>colums-1) //数组越界  不进行处理 
            return false;

        if(visited[x][y]|| grid[x][y]=='0')
            return false;    
        qp.push(make_pair(x,y));
        visited[x][y]=true;  
        return true;   

        
    }    

public:
    int numIslands(vector<vector<char> >& grid) {
        //广度度优先搜索查找岛屿
        if(grid.empty()|| grid[0].empty() ){
            return 0;
        }
        
        int rows=grid.size();
        int colums=grid[0].size();
        int res=0;
        queue <pair<int,int> > qp; //定义队列
        vector<vector<bool> > visited(rows,vector<bool>(colums,false));

        for(int i=0;i<rows;i++)
            for(int j=0;j<colums;j++){
                if(grid[i][j]=='0'|| visited[i][j]){
                    continue; //当前点为'0' 或者已经访问过 就直接跳过
                }
                res++; //新的岛屿 

                //接下来需要找到属于当前岛屿的所有点
                //将当前点放入队列
                qp.push(make_pair(i,j));
                visited[i][j]=true;
                while(!qp.empty()){
                    int queue_size=qp.size();
                    for(int i=0;i<queue_size;i++){

                    pair  pair_current_point=qp.front();
                    int x=pair_current_point.first;
                    int y=pair_current_point.second; 
                    //没有return 部分

                    //将当前node的所有邻居加入队列
                    pushDataToQueue(grid,visited,qp,rows,colums,x-1,y); //跟当前点有联系的四个点装入队列
                    pushDataToQueue(grid,visited,qp,rows,colums,x+1,y);
                    pushDataToQueue(grid,visited,qp,rows,colums,x,y-1);
                    pushDataToQueue(grid,visited,qp,rows,colums,x,y+1);
                    }

                    qp.pop();// 弹出第一个数据，不弹出数据队列永远不为空
                                


                }
             
            }
        return res;    
      



        
    }
};*/
//岛屿数量的深度优先求解算法

//深度优先搜索的java模板
/*
boolean DFS(Node cur, Node target, Set<Node> visited) {
    return true if cur is target;
    for (next : each neighbor of cur) {
        if (next is not in visited) {
            add next to visted;
            return true if DFS(next, target, visited) == true;
        }
    }
    return false;
}
 */
class Solution{
private:
    bool DFS(const int x,const int y, const int rows, const int colums,const vector<vector<char> >& grid,vector< vector<bool> >  &visited){
        // if(x<0||x>rows-1||y<0||y>colums-1)
        //     return false;
        // if(grid[x][y]==0)
        //     return false;
        //终止条件？？  //没有终止条件
        int a[4]={-1,1,0,0},b[4]={0,0,-1,1};

        for(int i=0;i<4;i++){  //判断四个邻居
            int cur_x=x+a[i];
            int cur_y=y+b[i];
            if(cur_x<0||cur_x>rows-1||cur_y<0||cur_y>colums-1)
                continue; //数据越界，这个点就不需要考虑了
            if( grid[cur_x][cur_y]== '1' && visited[cur_x][cur_y]==false){ //只有这个条件满足才会进行递归
                visited[cur_x][cur_y]=true;
                DFS(cur_x,cur_y,rows,colums,grid,visited);
            }        
        
        }  
        //尾递归？？   
        return false;
    }
public:
int numIslands(vector<vector<char> >& grid){

    //判断grid是否满足要求
    if(grid.empty()) return 0;
    if(grid[0].empty()) return 0;
    int rows=grid.size();
    int colums=grid[0].size();

    int num_is_lands=0; //初始化岛屿数量

    //定义visited 
    vector< vector<bool> > visited(rows,vector<bool>(colums,false));
    

    //遍历grid
    for(int i=0;i<rows;i++)
        for(int j=0;j<colums;j++){
            if(grid[i][j]=='0' || visited[i][j]==true) //如果当前值为0或者已经访问过 直接跳过
                continue;
            num_is_lands++;
            visited[i][j]=true;
            DFS(i,j,rows,colums,grid,visited);  //对当前点进行深度搜索，找到所有相连的所有岛屿         
        }

    return num_is_lands;
    }


};

