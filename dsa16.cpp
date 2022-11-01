#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node(){}
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insert(node *&head,int data){
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

int length (node*head){
    if(head==NULL){
        return 0;
    }
    return 1 + length(head->next);
}
void print(node * head){
    if(head==NULL){
        return;
    }
    node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void split(node*head,node*&front,node*&back){
    if(head==NULL || head->next==NULL){
        return;
    }
    int n = length(head);
    front = head;
    int count = 0;
    node *temp = head;
    while(count!= (n/2)-1){
        temp = temp->next;
        count++;
    }
    back = temp->next;
    temp->next = NULL;
    if(n&1){
        node *ptr = back;
        count = 0;
        while (count != (n / 2) - 1)
        {
            ptr = ptr->next;
            count++;
        }
        temp->next = ptr->next;
        ptr->next = NULL;
    }
}

int main(){
    node *head = NULL;
    insert(head, 2);
    insert(head, 1);
    //insert(head, 0);
    node *front = NULL;
    node *back = NULL;
    split(head, front, back);
    print(head);
    print(front);
    print(back);
}