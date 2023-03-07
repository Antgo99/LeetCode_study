#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        map<string,int> m={{"+",1},{"-",2},{"*",3},{"/",4}};
        stack<string> st;
        for(string s:tokens){
            if(m[s]>=1 && m[s]<=4){//是运算符就弹栈
                string opr_temp1 = st.top();
                st.pop();
                string opr_temp2 = st.top();
                st.pop();
                int temp;
                if(m[s] == 1) temp = stoi(opr_temp1) + stoi(opr_temp2);
                else if(m[s] == 2) temp = stoi(opr_temp2) - stoi(opr_temp1);
                else if(m[s] == 3) temp = stoi(opr_temp1) * stoi(opr_temp2);
                else if(m[s] == 4) temp = stoi(opr_temp2) / stoi(opr_temp1);
                string temp_res = to_string(temp);
                st.push(temp_res);
            }else{//不是运算符就压栈
               st.push(s); 
            }
        }
        return stoi(st.top());
    }
};
