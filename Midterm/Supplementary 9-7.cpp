#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = createNode(val);
    }
    else if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    int values[] = {2, 3, 9, 18, 0, 1, 4, 5};
    int n = sizeof(values) / sizeof(values[0]);

    // Insert all values
    cout << "Inserting values into the Binary Search Tree:\n";
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
        root = insert(root, values[i]);
    }

    cout << "\n\nTree Traversals:\n";

    cout << "In-order Traversal (L, Root, R): ";
    inorder(root);

    cout << "\nPre-order Traversal (Root, L, R): ";
    preorder(root);

    cout << "\nPost-order Traversal (L, R, Root): ";
    postorder(root);

    cout << "\n";

    return 0;
}
