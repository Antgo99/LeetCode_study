#include<bits/stdc++.h>
using namespace std;

int OuNumberSum(int number){
    int sum=0;
    if(number/10 == 0){
        if(number%2==0) return number;
        else return 0;
    }else{
        while(1){
            int a=number%10;
            if(a%2==0) sum+=a;
            number /= 10;
            if(number == 0) break;
        }
    }
    return sum;
}

int main(){
    int number;
    while(cin>>number){
        cout<<OuNumberSum(number)<<endl;
        cout<<endl;
    }
    return 0;
}
