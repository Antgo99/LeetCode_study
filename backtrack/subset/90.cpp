/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 22:04:18
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-24 19:51:52
 * @FilePath: \LeetCode\backtrack\subset\90.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums,int pos){
        // for(int i=0;i<result.size();i++){
        //     if(result[i] == path) return; 
        // }
        result.push_back(path);
        if(pos >= nums.size()){
            return;
        }

        for(int i=pos;i<nums.size();i++){
            if(i > pos && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());//去重需要排序
        backtracking(nums,0);
        return result;
    }
};
