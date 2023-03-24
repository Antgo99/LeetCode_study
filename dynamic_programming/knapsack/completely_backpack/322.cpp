#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){//遍历物品
            for(int j=coins[i];j<=amount;j++){//遍历背包
                if(dp[j-coins[i]] != INT_MAX){
                    dp[j] = min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
