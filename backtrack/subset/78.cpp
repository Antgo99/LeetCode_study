/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 22:04:13
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-24 19:25:44
 * @FilePath: \LeetCode\backtrack\subset\78.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    /*子集问题实际上是要得到树的所有节点，不需要剪枝*/
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums,int pos){
        result.push_back(path);//每次都要把结果放进去，不需要进行到最后 即不存在剪枝的条件
        if(pos >= nums.size()){
            return;
        }

        for(int i=pos;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};
