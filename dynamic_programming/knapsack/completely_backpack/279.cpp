/*
    20230316
    和322可以说是一模一样
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // vector<int> dp(n+1,INT_MAX);
        // dp[0]=0;
        // for(int i=0;i<=n;i++){//遍历背包
        //     for(int j=1;j*j<=i;j++){//遍历物品
        //         dp[i] = min(dp[i],dp[i-j*j]+1);
        //     }
        // }
        // return dp[n];
        vector<int> nums;
        for(int i=1;i<=n;i++){
            if(sqrt(i) == (int) sqrt(i)){
                nums.push_back(i);
            }
        }
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){//遍历物品
            for(int j=nums[i];j<=n;j++){//遍历背包
                dp[j] = min(dp[j],dp[j-nums[i]]+1);
            }
        }
        return dp[n];
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    cout<<s.numSquares(n)<<endl;
    return 0;
}
