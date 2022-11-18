#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(node *head){
    node *n = head;
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void start(node *&head, int data){
    node *n = new node(data);
    n->next = head;
    head = n;
}

//indexing from zero
void insert(node *&head, int data, int pos)
{
    if (pos == 0){
        start(head, data);
        return;
    }
    node *temp = head;
    // we are going to one node before the position so we can ass easily
    while (temp->next != NULL && pos != 1){
        temp = temp->next;
        pos--;
    }
    // if position is not equal to 1 that means the position index we got is greater than the length of the node
    if (pos != 1){
        cout << " ERROR : INVALID POSITION " << endl;
        return;
    }
    node *n = new node(data);
    n->next = temp->next;
    temp->next = n;
}

int main(){
    node *head = NULL;
    start(head, 6);
    insert(head, 2, 0);
    print(head);
    insert(head, 9, 3);
    print(head);
    insert(head, 4, 2);
    print(head);
    insert(head, 8, 2);
    print(head);
}