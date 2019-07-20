/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (66.53%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    41.8K
 * Total Submissions: 62.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//非递归遍历的模板
/*   
boolean DFS(int root, int target) {
    Set<Node> visited;
    Stack<Node> s;
    add root to s;
    while (s is not empty) {
        Node cur = the top element in s;
        return true if cur is target;
        for (Node next : the neighbors of cur) {
            if (next is not in visited) {
                add next to s;
                add next to visited;
            }
        }
        remove cur from s;
    }
    return false;
} */


#include <vector>
#include <stack>
using namespace std;

/* */
// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//   };


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode*> st_tree;
        vector<int >  v_result;

        //add root to st_tree//
        // if(!root)
        //     st_tree.push(root);
        

        TreeNode* p_cur_node=root;

        while( p_cur_node || !st_tree.empty()){
            while(p_cur_node){
                st_tree.push(p_cur_node);
                p_cur_node=p_cur_node->left;//先遍历左子树
                
            }
            //p_cur_node==nullptr
            if(!st_tree.empty()){
            p_cur_node=st_tree.top();
            st_tree.pop();
            v_result.push_back(p_cur_node->val);//访问元素
            p_cur_node=p_cur_node->right;//

            }

        }


        

    return v_result;
        
    }
};

