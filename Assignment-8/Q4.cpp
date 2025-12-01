#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insertBST(root->left, key);
    else if (key > root->data) root->right = insertBST(root->right, key);
    return root;
}

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root1 = nullptr;
    int keys1[] = {20, 10, 30, 5, 15, 25, 35};
    for (int k : keys1) root1 = insertBST(root1, k);
    cout << (isBST(root1) ? "Tree1 is a BST\n" : "Tree1 is NOT a BST\n");

    Node* root2 = new Node(20);
    root2->left = new Node(30);
    root2->right = new Node(10);
    cout << (isBST(root2) ? "Tree2 is a BST\n" : "Tree2 is NOT a BST\n");

    return 0;
}