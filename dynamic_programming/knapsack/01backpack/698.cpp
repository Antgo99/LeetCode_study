/*
    20230314
    划分k个相等的子集
        对代码中的位运算其实没太搞懂
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int num:nums) sum+=num;//求和
        if(sum % k != 0) return false;//不能整除时返回false
        int bagweight = sum/k;//计算每部分的大小
        sort(nums.begin(),nums.end());//排序，方便剪枝
        if(nums.back() > bagweight) return false;//最大值比目标值还大，一定误解

        int n=nums.size();
        vector<int> dp(1<<n,-1);//记录每个数字的使用状态
        dp[0]=0;
        for(int i=0;i< 1<<n;i++){
            if(dp[i] < 0) continue;//还没更新，-1表示未达
            for(int j=0;j<n && dp[i]+nums[j] <= bagweight;j++){
                if((i>>j) & 1 == 1) continue;//不太懂？
                dp[i | (1<<j)] = (dp[i] + nums[j]) % bagweight;//更新下一个状态 （不太懂？）
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};

int main(){
    vector<int> nums={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    Solution s;
    cout<<s.canPartitionKSubsets(nums,4)<<endl;
    return 0;
}
