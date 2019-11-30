#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

void preorder(Node *root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inlevel(Node *root) {
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        Node *n = q.front();
        q.pop();
        cout << n->data << " ";
        if (n->left != nullptr) q.push(n->left);
        if (n->right != nullptr) q.push(n->right);
    }
}

// type can be:
//      1 => preorder
//      2 => inorder
//      3 => postorder
//      4 => inlevel
void trasverse(int type, Node *root) {
    switch(type) {
        case 1:
            cout << "Pre order:" << endl;
            preorder(root);
            cout << endl;
            break;
        case 2:
            cout << "In order:" << endl;
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Post order:" << endl;
            postorder(root);
            cout << endl;
            break;
        case 4:
            cout << "In level:" << endl;
            inlevel(root);
            cout << endl;
            break;
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    trasverse(1, root);
    trasverse(2, root);
    trasverse(3, root);
    trasverse(4, root);
    return 0;
}
