#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q;
    public:
    // push operation
    void push(int x){
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n;i++){
            int value = q.front();
            q.pop();
            q.push(value);
        }
    }
    // pop operation
    int pop(){
        int value = q.front();
        q.pop();
        return value;
    }
    //accessing top value
    int top(){
        return q.front();
    }
    //finding size of the stack
    int size(){
        return q.size();
    }


};