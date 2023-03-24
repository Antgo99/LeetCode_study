/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 22:03:41
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-23 20:56:09
 * @FilePath: \LeetCode\backtrack\combination\40.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
#include<unordered_map>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target,int sum,int pos){
        if(sum > target) return;
        if(sum == target){
            result.push_back(path);
            return;
        }

        for(int i=pos;i<candidates.size() && sum + candidates[i] <= target;i++){
            if(i > pos && candidates[i] == candidates[i-1]) continue;//去重
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates,target,sum,i+1);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0);
        return result;
    }
};
