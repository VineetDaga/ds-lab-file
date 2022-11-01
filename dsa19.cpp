#include<iostream>
using namespace std;
#include<stack>

class queue{
    public:
        stack<int> in;
        stack<int> out;

        //push operation
        void Push(int x){
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
            return x;
        }

        //peek operation
        int Top(){
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