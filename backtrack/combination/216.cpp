#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n,int k,int startIndex,int sum){
        //剪枝
        if(sum > n) return;
        if(path.size() == k && sum == n){//终止条件
            result.push_back(path);
            return;
        }

        for(int i=startIndex;i<=9 - (k-path.size()) + 1;i++){
            path.push_back(i);
            sum += i;
            backtracking(n,k,i+1,sum);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n,k,1,0);
        return result;
    }
};
