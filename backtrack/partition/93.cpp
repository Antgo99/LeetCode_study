/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 22:04:02
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-23 22:10:00
 * @FilePath: \LeetCode\backtrack\partition\93.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<string> result;
    //判断一个s[start,end]在start到end之间是否合法
    bool isVaild(string& s,int start,int end){
        if(start > end) return false;
        if(s[start] == '0' && start != end) return false;//以0开头的串不合法

        int num=0;
        for(int i=start;i<=end;i++){
            //遇到非法数字
            if(s[i] < '0' || s[i] > '9') return false;
            num = num*10 + (s[i] - '0');
            if(num > 255) return false;//超过255限制的也不合法
        }
        return true;
    }
    void backtracking(string s,int pos,int dotNum){
        if(dotNum == 3){
            //判断第四段是否是合法 合法就放进结果集中
            if(isVaild(s,pos,s.size()-1)){
                result.push_back(s);
            }
            return;
        }

        for(int i=pos;i<s.size();i++){
            if(isVaild(s,pos,i)){//判断s[pos,i]是否合法
                s.insert(s.begin()+i+1,'.');//加入.
                dotNum++;//.的数量+1
                backtracking(s,i+2,dotNum);//递归
                dotNum--;//回溯
                s.erase(s.begin()+i+1);//回溯掉.
            }else break;//不合法就直接结束本层循环
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length() < 4 || s.length() > 12) return result;
        backtracking(s,0,0);
        return result;
    }
};
