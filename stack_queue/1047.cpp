#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res="";
        for(char c:s){
            if(!st.empty()){
                if(c == st.top()) st.pop();
                else st.push(c);
            }else st.push(c);
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.removeDuplicates("abbaca");
    return 0;
}