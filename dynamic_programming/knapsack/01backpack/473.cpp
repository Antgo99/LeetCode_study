/*
    20230314
    698中k=4的版本
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int num:matchsticks) sum+=num;
        if(sum % 4 != 0) return false;
        sort(matchsticks.begin(),matchsticks.end());
        int bagweight = sum/4;
        if(matchsticks.back() > bagweight) return false;

        int n=matchsticks.size();
        vector<int> dp(1<<n,-1);
        dp[0]=0;
        for(int i=0;i< 1<<n;i++){
            if(dp[i] < 0) continue;
            for(int j=0;j<n && dp[i]+matchsticks[j] <= bagweight;j++){
                if((i>>j) & 1 == 1) continue;
                dp[i | (1<<j)] = (dp[i] + matchsticks[j]) % bagweight;
            }
        }
        return dp[(1<<n) - 1] == 0;
    }
};

int main(){
    vector<int> nums={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    Solution s;
    cout<<s.makesquare(nums)<<endl;
    return 0;
}
