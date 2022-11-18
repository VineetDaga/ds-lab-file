#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q;
    public:
    // push operation
    void push(int x){
        int n = q.size();
        cout << x << " is pushed in the stack" << endl;
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
        cout << value << " is popped from the stack" << endl;
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

int main(){
    stack s;
    s.push(6);
    s.pop();
    s.push(8);
    s.push(7);
    s.push(2);
    cout << "top element: " << s.top() << endl;
    cout << "size of stack: " << s.size() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
}