#include<iostream>
using namespace std;
#include<stack>

class queue{
    public:
        stack<int> in;
        stack<int> out;

        //push operation
        void Push(int x){
            cout << x << " is enqueued in the queue" << endl;
            in.push(x);
        }

        //pop operation
        int Pop(){
            if(out.empty()){
                while(in.size()){
                    out.push(in.top());
                    in.pop();
                }
            }
            int x = out.top();
            out.pop();
            cout << x << " is dequeued from the queue" << endl;
            return x;
        }

        //peek operation
        int fornt(){
            if(out.empty()){
                while(in.size()){
                    out.push(in.top());
                    in.pop();
                }
            }
            return out.top();
        }

        // size of the queue
        int size(){
            return in.size() + out.size();
        }
};
int main(){
    queue s;
    s.Push(6);
    s.Pop();
    s.Push(8);
    s.Push(7);
    s.Push(2);
    cout << "top element: " << s.fornt() << endl;
    cout << "size of queue: " << s.size() << endl;
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
}