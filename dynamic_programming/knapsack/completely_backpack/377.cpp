/*
    20230315
    排列组合
    和518不同的是，518是组合问题，不需要考虑顺序，而本题是排列问题，需要考虑顺序
    1.dp[i]:凑成目标正整数为i的排列个数为dp[i]
    2.递推公式：dp[i]+=dp[i-nums[j]]
    3.初始化 dp[0]=1
    4.确定顺序
        如果是求组合就是外层for循环遍历物品，内层for遍历背包
        如果是求排列就是外层for遍历背包，内层for循环遍历物品
        所以本题的遍历顺序是target放在外循环，将nums放在内循环，内循环从前到后遍历
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j] >= 0 && dp[i]+dp[i-nums[j]] < INT_MAX){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};
