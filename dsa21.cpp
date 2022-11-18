#include<iostream>
#include<queue>
#include<climits>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node *levelorderconstruct(node *root)
{
    queue<node *> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return root;
    }
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << " Enter Left leafnode of " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << " Enter right leafnode of " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}

bool isBST(node * root,int min,int max){
    // base case
    if(root == NULL){
        return true;
    }
    if(root->data >=min && root->data <=max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return (left && right);
    }
    else{
        return false;
    }
}
bool BST(node * root){
    return isBST(root, INT_MIN, INT_MAX);
}

int main(){
    node *root1 = NULL;
    root1 = levelorderconstruct(root1);
    cout << " the given binary tree is BST or not : " << BST(root1);
    cout << endl;
    node *root2 = NULL;
    root2 = levelorderconstruct(root2);
    cout << " the given binary tree is BST or not : " << BST(root2);
    cout << endl;
    // 9 6 12 3 7 10 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
}