#include <iostream>
#include <cmath>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* root = NULL;

int Height(BSTNode* node) {
    if (node == NULL) {
        return 0;
    }
    int LeftHeight = Height(node->left);
    int RightHeight = Height(node->right);
    return max(LeftHeight, RightHeight) + 1;
}

BSTNode* RRImbalance(BSTNode* node) { // SHIFT LEFT..
    BSTNode* Nnode = node->right;
    BSTNode* LC = Nnode->left;
    Nnode->left = node;
    node->right = LC;
    return Nnode;
}

void PreOrder(BSTNode* node) {
    if (node != NULL) {
        cout << node->data << endl;
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

BSTNode* insertion(BSTNode* node, int value) {
    if (node == NULL) {
        BSTNode* temp = new BSTNode();
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if (value > node->data) {
        node->right = insertion(node->right, value);
    } else {
        node->left = insertion(node->left, value);
    }

    // After inserting, check and correct for LL imbalance
    int leftHeight = Height(node->left);
    int rightHeight = Height(node->right);

    if (abs(leftHeight - rightHeight) > 1) {
        node = RRImbalance(node);  // Correct imbalance and update the node
    }

    return node;  // Return the updated node
}

int main() {
    root = insertion(root, 23);
    root = insertion(root, 45);
    root = insertion(root, 70);

    PreOrder(root); // Traverse the tree and print the output

    return 0;
}
