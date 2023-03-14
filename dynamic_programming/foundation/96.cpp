/*
    比较经典的一个dp题
    20230313
    根节点左边的数都比根节点小，根节点右边的数都比根节点大
    比如n=3的情况：
    根节点为1：左边0个节点*右边2个节点
    根节点为2：左边1个节点*右边一个节点
    根节点为3：左边2个节点*右边0个节点
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;//空二叉树也是一种二叉搜索树
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};

int main(){
    int n;
    while(true){
        cin>>n;
        Solution s;
        cout<<s.numTrees(n)<<endl;
    }
    return 0;
}
