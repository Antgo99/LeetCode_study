/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-24 19:53:08
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-24 20:14:53
 * @FilePath: \LeetCode\backtrack\subset\491.cpp
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
    void backtracking(vector<int>& nums,int pos){
        if(path.size() >= 2){
            result.push_back(path);
        }

        /*这里不用i>pos && nums[i] == nums[i-1]是因为数组不能排序 如果要用这种方式排序 那么就需要给数组排序*/
        unordered_set<int> uset;//set去重
        for(int i=pos;i<nums.size();i++){
            if((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) continue;
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};
