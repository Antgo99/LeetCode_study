#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
    queue<int> que_fir;
    queue<int> que_sec;

    MyStack() {

    }
    
    void push(int x) {
        que_fir.push(x);
    }
    
    int pop() {
        int size = que_fir.size();
        size--;
        while(size--){
            que_sec.push(que_fir.front());
            que_fir.pop();
        }

        int temp = que_fir.front();
        que_fir.pop();
        que_fir = que_sec;
        while(!que_sec.empty()){
            que_sec.pop();
        }
        return temp;
    }
    
    int top() {
        return que_fir.back();
    }
    
    bool empty() {
        return que_fir.empty();
    }
};