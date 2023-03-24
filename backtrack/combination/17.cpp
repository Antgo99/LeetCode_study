/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 22:03:30
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-23 20:23:09
 * @FilePath: \LeetCode\backtrack\combination\17.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
#include<unordered_map>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    map<int,string> m={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    vector<string> result;
    string path;
    void backtracking(string digits,int pos){
        if(pos == digits.length()){
            result.push_back(path);
            return;
        }
        int dight = (int) digits[pos];
        for(auto i:m[dight]){
            path.push_back(i);
            backtracking(digits,pos+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;
        backtracking(digits,0);
        return result;
    }
};
