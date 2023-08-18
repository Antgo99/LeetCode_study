#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        getchar();
        for(int i=0;i<n;i++){
            string ss,result="";
            getline(cin,ss);
            if(ss[0] >= 'a' && ss[0] <= 'z'){
                ss[0] -= 32;
            }
            result += ss[0];
            for(int j=0;j<ss.length()-1;j++){
                if(ss[j] == ' ' && ss[j+1] != ' '){
                    if(ss[j+1] >= 'a' && ss[j+1] <= 'z'){
                        ss[j+1] -= 32;
                    }
                    result += ss[j+1];
                }
            }
            cout<<result<<endl;
        }
    }
    return 0;
}
