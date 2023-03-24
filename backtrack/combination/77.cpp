#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;//记录结果
    vector<int> path;//记录中间数据
    void backtracking(int n,int k,int startIndex){//startIndex为开始的位置 避免重复取数
        if(path.size() == k){
            result.push_back(path);
            return;
        }

        for(int i = startIndex;i<=n;i++){//还可以剪枝 i<=n改为 i<=n-(k-path.size())+1 当剩下的元素不够时就剪枝掉
            path.push_back(i);//处理节点
            backtracking(n,k,i+1);//递归
            path.pop_back();//回溯
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return result;
    }
};
