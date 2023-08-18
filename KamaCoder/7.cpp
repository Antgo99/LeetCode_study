#include<bits/stdc++.h>
using namespace std;

map<char,int> m{{'A',4},{'B',3},{'C',2},{'D',1},{'F',0}};

int main(){
    string ss;
    while(getline(cin,ss)){
        float result = 0;
        int number = 0;
        int flag = 0;
        for(char c : ss){
            if(c!=' '){
                if(m.find(c) == m.end()){//没找到相应的字母
                    cout<<"Unknown"<<endl;
                    flag = 1;
                    break;
                }else{//找到了相应的字母
                    result += m[c];
                    number++;
                }
            }
        }
        if(!flag){
            cout<<fixed<<setprecision(2);
            cout<<result/number<<endl;
            //printf("%.2f\n",result/number);
        }
    }
    return 0;
}

/*
    总结：
        1.用map<char,int> 键为char类型，值为int类型，用于匹配字母和分数
        2.用map.find(键)来查找是否存在该键，对存在键的值累加
        3.对有空格的字符串需要用getline(cin,string)
        4.对输出需要保留多少小数位的，c++是cout<<fixed<<setprecision(n);n为保留的小数位，这样之后输出的数都是保留n位小数；
            c是printf("%.2f\n",result)。

*/
