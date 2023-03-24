/*
    20230315
    排列组合问题
    和494相同，一个是01背包问题，这个是完全背包问题
    1.dp[j]:凑成总金额j的货币组合数最大为dp[j]
    2.既然是组合问题 那么dp[j]就是dp[j-coins[i]]相加
        递推公式：dp[j]+=dp[j-conis[i]]
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
