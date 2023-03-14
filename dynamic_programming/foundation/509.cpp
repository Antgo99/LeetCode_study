/*
    20230313
    斐波那契
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //递归
    int fib_Recursive(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fib_Recursive(n-1)+fib_Recursive(n-2);    
    }

    int fib(int n){
        //动规五部曲
        /*1.确定dp数组以及下标的含义
            dp[i]
        */
        //2.确定递归公式 dp[i] = dp[i-1] +dp[i-2]

        //3.dp数组如何初始化 dp[0]=0 dp[1]=1

        //4.确定遍历顺序 从前到后的顺序遍历

        //5.举例推到dp数组
        if(n<=1) return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    int n;
    while(true){
        cin>>n;
        Solution s;
        cout<<s.fib_Recursive(n)<<endl;
    }
    return 0;
}
