#include<iostream>
using namespace std;
#include<queue>

class node{
    public:
        int data;
        node *left;
        node *right;
        node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void inorder(node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//contructing binary tree
node * levelorderconstruct(node * root){
    queue<node *> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    if(data == -1){
        return root;
    }
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        cout << " Enter Left leafnode of " << temp->data<< endl;
        int leftdata;
        cin >> leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << " Enter right leafnode of " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}

int main(){
    node *root = NULL;
    root = levelorderconstruct(root);
    inorder(root);
}