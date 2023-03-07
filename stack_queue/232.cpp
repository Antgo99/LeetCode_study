#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> sk_in;
    stack<int> sk_out;

    MyQueue() {

    }
    
    void push(int x) {
        sk_in.push(x);
    }
    
    int pop() {
        if(sk_out.empty()){
            while(!sk_in.empty()){
                sk_out.push(sk_in.top());
                sk_in.pop();
            }
        }
        int temp = sk_out.top();
        sk_out.pop();
        return temp;
    }
    
    int peek() {
        int temp = this->pop();
        sk_out.push(temp);
        return temp;
    }
    
    bool empty() {
        return sk_in.empty() && sk_out.empty();
    }
};