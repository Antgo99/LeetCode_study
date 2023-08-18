#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,k;
    while(cin>>m>>k && m!=0&&k!=0){
        int day = m;
        while(1){
            int mDay,kDay;
            mDay = m / k;
            kDay = m % k;
            m = mDay + kDay;
            day += mDay;
            if(m / k == 0) break;
        }
        cout<<day<<endl;
    }
    return 0;
}
