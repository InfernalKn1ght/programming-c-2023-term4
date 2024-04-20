#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node *root;
    bool empty;

    Node *getLeftNode(Node *root);
    Node *&getLeftLeave(Node *&root);
    void print(Node *root, int indent);
    Node *getSecondLeave(Node *root, int *num);
    void rotateLeft(Node *&root);

public:
    Node *getLeftNodeRoot();
    void rotateLeftRoot();
    Node *getLeftGrandsonRoot();
    Node *&getLeftLeaveRoot();
    void removeLeftLeave();
    void add(int data);
    void printRoot();
    Node *getSecondLeaveRoot();

    BinaryTree() : root(new Node), empty(1) {}
};

Node *BinaryTree::getLeftGrandsonRoot() {
    if (root && root->left) {
        return root->left->left;
    } else {
        return nullptr;
    }
}

Node *BinaryTree::getLeftNode(Node *root) {
    if (root->left) {
        return getLeftNode(root->left);
    } else {
        return root;
    }
}

Node *BinaryTree::getLeftNodeRoot() {
    return getLeftNode(root);
}

void BinaryTree::rotateLeft(Node *&root) {
    if (root && root->right) {
        Node *temp = root;
        root = root->right;
        temp->right = root->left;
        root->left = temp;
    }
}

void BinaryTree::rotateLeftRoot() {
    rotateLeft(root);
}

Node *&BinaryTree::getLeftLeave(Node *&root) {
    if (root->left) {
        return getLeftLeave(root->left);
    } else if (root->right) {
        return getLeftLeave(root->right);
    } else {
        return root;
    }
}

Node *&BinaryTree::getLeftLeaveRoot() {
    return getLeftLeave(root);
}

void BinaryTree::removeLeftLeave() {
    getLeftLeaveRoot() = nullptr;
}

void BinaryTree::add(int data) {
    if (empty) {
        root->data = data;
        empty = 0;
    } else {
        Node *temp = root;
        while (temp) {
            if (temp->data > data) {
                if (temp->left) {
                    temp = temp->left;
                } else {
                    temp->left = new Node;
                    temp->left->data = data;
                    break;
                }
            } else {
                if (temp->right) {
                    temp = temp->right;
                } else {
                    temp->right = new Node;
                    temp->right->data = data;
                    break;
                }
            }
        }
    }
}

void BinaryTree::print(Node *root, int indent = 0) {
    if (root == nullptr) return;
    print(root->right, indent + 3);

    for (int i = 0; i < indent; ++i) {
        std::cout << ' ';
    }
    std::cout << root->data << std::endl;

    print(root->left, indent + 3);
}

void BinaryTree::printRoot() {
    print(root);
}


int main(int argc, char *argv[]) {
    BinaryTree tree;

    tree.add(7);
    tree.add(4);
    tree.add(6);
    tree.add(10);
    tree.add(1);
    tree.add(8);
    tree.add(12);

    tree.printRoot();

    std::cout << std::endl;

    tree.rotateLeftRoot();


    tree.printRoot();

    return EXIT_SUCCESS;
}