#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        //排列问题
        vector<int> nums={1,2};
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                if(i-nums[j] >= 0){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[n];
    }
};
