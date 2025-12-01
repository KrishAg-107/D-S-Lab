#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* n) {
    if (!root || !n) return nullptr;
    if (n->right) return findMin(n->right);
    Node* succ = nullptr;
    Node* curr = root;
    while (curr) {
        if (n->data < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if (n->data > curr->data) {
            curr = curr->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* n) {
    if (!root || !n) return nullptr;
    if (n->left) return findMax(n->left);
    Node* pred = nullptr;
    Node* curr = root;
    while (curr) {
        if (n->data > curr->data) {
            pred = curr;
            curr = curr->right;
        } else if (n->data < curr->data) {
            curr = curr->left;
        } else break;
    }
    return pred;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = nullptr;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};
    for (int k : keys) root = insert(root, k);

    cout << "Inorder of BST: ";
    inorderPrint(root);
    cout << "\n\n";

    int x = 10;
    Node* r1 = searchRecursive(root, x);
    cout << "Recursive search for " << x << ": " << (r1 ? "Found" : "Not Found") << "\n";

    int y = 15;
    Node* r2 = searchIterative(root, y);
    cout << "Iterative search for " << y << ": " << (r2 ? "Found" : "Not Found") << "\n\n";

    Node* mn = findMin(root);
    Node* mx = findMax(root);
    cout << "Minimum element: " << (mn ? mn->data : INT_MIN) << "\n";
    cout << "Maximum element: " << (mx ? mx->data : INT_MAX) << "\n\n";

    Node* node = searchIterative(root, 12);
    if (node) {
        Node* succ = inorderSuccessor(root, node);
        Node* pred = inorderPredecessor(root, node);
        cout << "Node: " << node->data << "\n";
        cout << "Inorder Successor: " << (succ ? to_string(succ->data) : string("NULL")) << "\n";
        cout << "Inorder Predecessor: " << (pred ? to_string(pred->data) : string("NULL")) << "\n";
    } else {
        cout << "Node 12 not found\n";
    }

    return 0;
}