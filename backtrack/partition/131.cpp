/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 22:03:55
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-23 21:30:04
 * @FilePath: \LeetCode\backtrack\partition\131.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(string& s,int start,int end){
        //使用双指针 前后两个指针指向的元素都相等就是回文串
        for(int i=start,j=end;i<j;i++,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    void backtracking(string s,int pos){
        if(pos >= s.length()){//截取到字符串的最后 就停止
            result.push_back(path);
            return;
        }
        
        for(int i=pos;i<s.size();i++){
            if(isPalindrome(s,pos,i)){//找到回文串就加进来
                string str = s.substr(pos,i-pos+1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
};
