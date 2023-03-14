#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
            1.dp[i]的含义为到达第i台阶所花费的最小体力为dp[i]
            2.得到dp[i]有两个途径，dp[i-1]和dp[i-2]
                dp[i-1]跳到dp[i]需要花费dp[i-1]+cost[i-1]
                dp[i-2]跳到dp[i]需要花费dp[i-2]+cost[i-2]
                dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
            3.初始化
                dp[0]=0 dp[1]=0
        */
        int n=cost.size();
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};

int main(){
    vector<int> cost={10,15,20};
    while(true){
        Solution s;
        cout<<s.minCostClimbingStairs(cost);
    }
    return 0;
}
