/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-17 21:18:03
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-17 22:16:36
 * @FilePath: \LeetCode\hash_table\15.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
    20230317
    15.三数之和
    给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
    同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
    注意：答案中不可以包含重复的三元组。

    输入：nums = [-1,0,1,2,-1,-4]
    输出：[[-1,-1,2],[-1,0,1]]
    解释：
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
    不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
    注意，输出的顺序和三元组的顺序并不重要。
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

//去重是一个关键 
class Solution {
public:
    //20230317 最新的力扣会超时 哈希表的方式
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());//排序
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0) continue;//第一个数就超过0 直接剪枝
            if(i>0 && nums[i] == nums[i-1]) continue;//给nums[i]去重
            unordered_set<int> us;
            for(int j=i+1;j<nums.size();j++){
                if(j > i+2 && nums[j] == nums[j-1] && nums[j-1] == nums[j-2]) continue;//给nus[j]去重
                int c = -(nums[i]+nums[j]);
                if(us.find(c) != us.end()){
                    res.push_back({nums[i],nums[j],c});
                    us.erase(c);//给nums[k]去重
                }else{
                    us.insert(nums[j]);
                }
            }
        }
        return res;
    }

    //双指针做法
    vector<vector<int>> threeSum_double_pointer(vector<int>& nums){
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0) return res;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right] > 0 ) right--;
                else if(nums[i]+nums[left]+nums[right] < 0) left++;
                else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(right>left && nums[right] == nums[right-1]) right--;
                    while(right<left && nums[left] == nums[left-1]) left++;
                    //找到答案后双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return res;
    }

};
