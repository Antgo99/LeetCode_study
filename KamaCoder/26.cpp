#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string ss;
        cin>>ss;
        int minOpt = 0;//最小操作数
        /*思路：1.统计每个字母出现的频率
                2.每次删除两个相同的字母，新增一个未出现的字母；如果字母全部都出现就将所有新增的字母转化为一个特定的字母，
                3.转化的这个特定的字母每删除两个就会新增一个，实际上每次操作只删除一个
        */
        vector<int> alp(26,0);//存储字母频率
        for(int i=0;i<ss.length();i++){
            alp[ss[i] - 97]++;//每个字母减去97，存储在0-26的数组中
        }
        for(int i=0;i<26;i++){
            minOpt += alp[i] / 2;
            alp[i] %= 2;
        }
        //统计未出现字母的个数
        int numAlp = 0;
        for(int i=0;i<26;i++){
            if(alp[i] == 0) numAlp++;
        }
        if(minOpt > numAlp){//如果需要新增的字母个数大于未出现的字母个数，
            int temp = minOpt - numAlp;//表示特定字母个数
            minOpt += temp;
        }
        cout<<minOpt<<endl;
    }
    return 0;
}
