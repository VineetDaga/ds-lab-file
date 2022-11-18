#include<iostream>
using namespace std;
#include<stack>
#include<queue>

queue<int> reverse(queue<int> &q, int k)
{
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    for (int i = 0; i < k; i++)
    {
        q.push(s.top());
        s.pop();
    }
    int n = q.size() - k;
    for (int i = 0; i < n; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}
void print(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    queue<int> q;
    for (int i = 0; i < 7;i++){
        q.push(i + 1);
    }
    int k;
    cout << "Enter the value of K: " << endl;
    cin >> k;
    cout << "BEFORE REVERSAL" << endl;
    print(q);
    reverse(q, k);
    cout << "AFTER REVERSAL" << endl;
    print(q);
}
