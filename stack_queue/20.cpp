#include<iostream>
#include<stack>
#include<map>
using namespace std;

class Solution {
public:
//直观解法
    bool isValid(string s) {
        stack<char> ss;
        int count = 0;
        for(char c:s){
            if(c == '(' || c == '{' || c == '['){
                ss.push(c);
            }else{
                count++;
                if(c == ')' && !ss.empty()){
                    if(ss.top() == '('){
                        ss.pop();
                        count--;
                    }
                }else if(c == '}' && !ss.empty()){
                    if(ss.top() == '{'){
                        ss.pop();
                        count--;
                    }
                }else if(c == ']' && !ss.empty()){
                    if(ss.top() == '['){
                        ss.pop();
                        count--;
                    }
                }
            }
        }
        if(ss.empty() && count == 0) return true;
        else return false;
    }
//利用map解法
    bool isValid_map(string s){
        map<char,int> m={{'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6}};
        stack<char> ss;
        bool vaild = true;
        for(char c:s){
            int flag = m[c];
            if(flag>=1 && flag<=3) ss.push(c);
            else if(!ss.empty() && m[c] == m[ss.top()] + 3) ss.pop();
            else{vaild = false;break;}
        }
        if(!ss.empty()) vaild = false;
        return vaild;
    }
};

int main(){
    Solution ss;
    cout<<ss.isValid_map("[]");
    return 0;
}