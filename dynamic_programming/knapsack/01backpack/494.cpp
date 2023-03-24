/*
    20230315
    排列组合的问题
    分成两种形式：加法的数和减法的数
    加法left 减法right
    left+right=sum
    left-right=target
    left=(target+sum)/2

    dp[j] 背包容量为j时，有dp[j]种方式
    对于容量为j时候，要把1~j的容量种方式相加
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(abs(target) > sum) return 0;
        if((target+sum) % 2 != 0) return 0;
        int bagweight = (target+sum)/2;
        vector<int> dp(bagweight+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=bagweight;j>=nums[i];j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[bagweight];
    }
};

int main(){
    vector<int> nums={1,1,1,1,1};
    Solution s;
    cout<<s.findTargetSumWays(nums,5)<<endl;
    return 0;
}
