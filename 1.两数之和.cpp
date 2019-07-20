/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        std::unordered_map<int,int>  umap;
        for(int i=0;i<nums.size();i++){
            auto umap_iter=umap.find(target-nums[i]);

            if(umap_iter==umap.end()){
                umap[nums[i]]=i;  //add to umap
            }

            else
            {              
                result.push_back(umap_iter->second);   //find success return
                result.push_back(i);
                 break; /* code */
            }
            
    
        }


        return  result;


    }
};

