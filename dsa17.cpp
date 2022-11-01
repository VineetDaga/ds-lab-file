#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node *prev;
        node(){}
        node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void insert(node *&head, int data, node *&tail)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        tail = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}

void pairs(node* head,int x,node*tail){
    node *first = head;
    node *last = tail;
    bool found = false;
    while(first!=last && last->next != first){
        if(first->data +last->data ==x){
            found = true;
            cout << "(" << first->data << ", "
                 << last->data << ")" << endl;

            // move first in forward direction
            first = first->next;

            // move second in backward direction
            last = last->prev;
        }
        else{
            if ((first->data + last->data) < x)
                first = first->next;
            else
                last = last->prev;
        }
    }
    if(found == false){
        cout << "no pair is found " << endl;
    }
}

int main(){
    node *head = NULL;
    node *tail = NULL;
    insert(head, 25, tail);
    insert(head, 19, tail);
    insert(head, 16, tail);
    insert(head, 12, tail);
    insert(head, 10, tail);
    insert(head, 9, tail);
    insert(head, 8, tail);
    insert(head, 7, tail);
    insert(head, 5, tail);
    insert(head, 2, tail);
    pairs(head, 35, tail);
}