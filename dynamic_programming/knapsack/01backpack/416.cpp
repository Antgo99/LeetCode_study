/*
    20230314 01背包
    划分两个相等的子集
    即取总和的一半为背包的重量，元素既是重量也是价值，然后直接套用01背包一维数组方式即可
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum += i;
        }
        if(sum % 2 != 0) return false;
        int bagweight = sum/2;
        vector<int> dp(10001,0);
        for(int i=0;i<nums.size();i++){
            for(int j=bagweight;j>=nums[i];j--){
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[bagweight] == bagweight) return true;
        else return false;
    }
};

int main(){
    vector<int> nums={1,5,11,5};
    Solution s;
    cout<<s.canPartition(nums)<<endl;
    return 0;
}
