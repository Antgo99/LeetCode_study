/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 22:04:30
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-24 20:36:00
 * @FilePath: \LeetCode\backtrack\arrange\47.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums,vector<bool>& used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        unordered_set<int> uset;//去重
        for(int i=0;i<nums.size();i++){
            if(used[i] == true || uset.find(nums[i]) != uset.end()) continue;
            used[i] = true;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums,used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};
