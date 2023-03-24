/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 22:04:25
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-24 20:27:16
 * @FilePath: \LeetCode\backtrack\arrange\46.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    /*全排列问题就不需要按pos来分，只需要标记用掉的元素*/
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums,vector<bool>& used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i] == true) continue;//标记的元素被用了
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums,used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};
