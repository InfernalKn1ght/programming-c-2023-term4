#include <iostream>

struct Node {
    int data;
    Node *up;
    Node *left;
    Node *right;
    Node(int data = 0) : data(data), up(nullptr), left(nullptr), right(nullptr) {}
};

class UTree {
public:
    Node *root;
    bool empty;
    void print(Node *root, int indent);
    void rotateLeft(Node *&root);

    void rotateLeftRoot();
    void add(int data);
    void printRoot();

    void remove(Node *&node);

    UTree() : root(new Node), empty(1) {}
};

void UTree::rotateLeft(Node *&root) {
    if (root && root->right) {
        Node *temp = root;
        root = root->right;

        root->up = temp->up;

        if (root->left) {
            root->left->up = temp;
        }

        temp->right = root->left;

        temp->up = root;

        root->left = temp;
    }
}

void UTree::rotateLeftRoot() {
    rotateLeft(root);
}

void UTree::add(int data) {
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
                    temp->left->up = temp;
                    temp->left->data = data;
                    break;
                }
            } else {
                if (temp->right) {
                    temp = temp->right;
                } else {
                    temp->right = new Node;
                    temp->right->up = temp;
                    temp->right->data = data;
                    break;
                }
            }
        }
    }
}

void UTree::print(Node *root, int indent = 0) {
    if (root == nullptr) return;
    print(root->right, indent + 3);

    for (int i = 0; i < indent; ++i) {
        std::cout << ' ';
    }
    std::cout << root->data << std::endl;

    print(root->left, indent + 3);
}

void UTree::printRoot() {
    print(root);
}

void UTree::remove(Node *&node) {
    if (!node) {
        return;
    }
    if (node->right) {
        Node *temp = node->left;
        node->right->up = node->up;
        node = node->right;

        if (!node->left) {
            node->left = temp;
        } else {
            Node *temp_left = node->left;
            while (temp_left->left) {
                temp_left = temp_left->left;
            }
            temp_left->left = temp;
        }

    } else if (node->left) {
        node->left->up = node->up;
        node = node->left;

    } else {
        delete node;
        node = nullptr;
    }
}

int main(int argc, char *argv[]) {
    UTree tree;

    tree.add(7);
    tree.add(4);
    tree.add(6);
    tree.add(10);
    tree.add(14);
    tree.add(9);
    tree.add(1);

    tree.printRoot();

    tree.rotateLeftRoot();

    tree.remove(tree.root->right);

    tree.printRoot();

    return EXIT_SUCCESS;
}