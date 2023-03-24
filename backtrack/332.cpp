/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-24 20:57:28
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-24 21:13:40
 * @FilePath: \LeetCode\backtrack\332.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    //定义一个映射关系 出发机场和达到机场的映射关系 unordered_map<出发地,map<目的地，可用航班次数>> targets 用可用航班次数来标记路线，防止死循环
    unordered_map<string,map<string,int>> targets;
    bool backtracking(int ticketNum,vector<string>& result){
        if(ticketNum + 1 == result.size()){
            return true;
        }

        for(pair<const string,int>& target:targets[result[result.size() - 1]]){//这个target[result[result.size()-1]是最骚的 直接在列表中查找航班
            if(target.second > 0){//航班是否可用
                result.push_back(target.first);
                target.second--;//可用次数减1
                if(backtracking(ticketNum,result)) return true;
                target.second++;
                result.pop_back();
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        result.push_back("JFK");//记录起始机场
        //记录映射关系
        for(vector<string>& ticket:tickets){
            targets[ticket[0]][ticket[1]]++;
        }
        backtracking(tickets.size(),result);
        return result;
    }
};
