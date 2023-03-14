/*
    20230314
    就是将石头分成尽可能相等的两堆 这样碰撞就是最小值
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int num:stones) sum+=num;
        vector<int> dp(1501,0);
        int bagweight = sum/2;
        for(int i=0;i<stones.size();i++){
            for(int j=bagweight;j>=stones[i];j--){
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return sum-2*dp[bagweight];
    }
};
