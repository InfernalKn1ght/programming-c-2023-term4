#include "BTree.h"
#include <iostream>

Node *BTree::getLeftGrandsonRoot() {
    if (root && root->left) {
        return root->left->left;
    } else {
        return nullptr;
    }
}

Node *BTree::getLeftNode(Node *root) {
    if (root->left) {
        return getLeftNode(root->left);
    } else {
        return root;
    }
}

Node *BTree::getLeftNodeRoot() {
    return getLeftNode(root);
}

void BTree::rotateLeft(Node *&root) {
    if (root && root->right) {
        Node *temp = root;
        root = root->right;
        temp->right = root->left;
        root->left = temp;
    }
}

void BTree::rotateLeftRoot() {
    rotateLeft(root);
}

Node *&BTree::getLeftLeave(Node *&root) {
    if (root->left) {
        return getLeftLeave(root->left);
    } else if (root->right) {
        return getLeftLeave(root->right);
    } else {
        return root;
    }
}

Node *&BTree::getLeftLeaveRoot() {
    return getLeftLeave(root);
}

void BTree::removeLeftLeave() {
    getLeftLeaveRoot() = nullptr;
}

void BTree::add(int data) {
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

void BTree::print(Node *root, int indent = 0) {
    if (root == nullptr) return;
    print(root->right, indent + 3);

    for (int i = 0; i < indent; ++i) {
        std::cout << ' ';
    }
    std::cout << root->data << std::endl;

    print(root->left, indent + 3);
}

void BTree::printRoot() {
    print(root);
}

int BTree::sum_subtree(Node *root) {
    if (!root) {
        return 0;
    }
    return root->data + sum_subtree(root->left) + sum_subtree(root->right);
}

int BTree::sum() {
    return sum_subtree(root);
}

int BTree::count_neg_subtree(Node *root) {
    int c = 0;
    if (!root) {
        return 0;
    } else if (root->data < 0) {
        c = 1;
    }
    return c + count_neg_subtree(root->left) + count_neg_subtree(root->right);
}

int BTree::count_neg() {
    return count_neg_subtree(root);
}

int BTree::height_subtree(Node *root) {
    if (!root) {
        return 0;
    }
    return 1 + std::max(height_subtree(root->left), height_subtree(root->right));
}

int BTree::height() {
    return height_subtree(root);
}

void BTree::reflect_subtree(Node *root) {
    if (root) {
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;

        reflect_subtree(root->left);
        reflect_subtree(root->right);
    }
}

void BTree::reflect() {
    reflect_subtree(root);
}

int BTree::mult_subtree(Node *root) {
    int c = 1;
    if (!root) {
        return 1;
    } else if (root->left && root->right) {
        c = root->data;
    }
    return c * mult_subtree(root->left) * mult_subtree(root->right);
}

int BTree::mult() {
    return mult_subtree(root);
}

int BTree::eval_subtree(Node *root) {
    if (root) {
        if (root->left || root->right) {
            int temp;
            switch (root->data) {
            case 1:
                return eval_subtree(root->left) + eval_subtree(root->right);
                break;

            case 2:
                return eval_subtree(root->left) - eval_subtree(root->right);
                break;

            case 3:
                return eval_subtree(root->left) * eval_subtree(root->right);
                break;

            case 4:
                temp = eval_subtree(root->right);
                if (temp) {
                    return eval_subtree(root->left) / eval_subtree(root->right);
                }
                return 0;
                break;

            default:
                break;
            }
        } else {
            return root->data;
        }
    }
    return 0;
}

int BTree::eval() {
    return eval_subtree(root);
}

int BTree::min_subtree(Node *root) {
    if (!root) {
        return 1000000000;
    }
    return std::min(root->data, std::min(min_subtree(root->left), min_subtree(root->right)));
}

int BTree::min() {
    if (!root) {
        return 0;
    }
    return min_subtree(root);
}

void delete_all_nodes(Node *root) {
    if (root) {
        delete_all_nodes(root->left);
        delete_all_nodes(root->right);
        delete root;
    }
}

void BTree::del0_subtree(Node *root) {
    if (root) {
        if (root->data == 0) {
            delete_all_nodes(root);
            root = nullptr;
            return;
        }
        if (root->left && root->left->data == 0) {
            delete_all_nodes(root->left);
            root->left = nullptr;
        }
        if (root->right && root->right->data == 0) {
            delete_all_nodes(root->right);
            root->right = nullptr;
        }
        del0_subtree(root->left);
        del0_subtree(root->right);
    }
}

void BTree::del0() {
    del0_subtree(root);
}

void BTree::del_leaves_subtree(Node *&root) {
    if (root) {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        } else {
            del_leaves_subtree(root->left);
            del_leaves_subtree(root->right);
        }
    }
}

void BTree::del_leaves() {
    del_leaves_subtree(root);
}

void BTree::enlarge_subtree(Node *&root, int d) {
    if (!root) {
        root = new Node(d);
        return;
    }
    enlarge_subtree(root->left, d);
    enlarge_subtree(root->right, d);
}

void BTree::enlarge(int d) {
    enlarge_subtree(root, d);
}

void BTree::del1_subtree(Node *&root) {
    if (root) {
        del1_subtree(root->left);
        del1_subtree(root->right);

        if (root->data == 1) {
            delete_all_nodes(root->left);
            root = root->right;
            return;
        }
        if (root->left && root->left->data == 1) {
            delete_all_nodes(root->left->left);
            root->left = root->left->right;
        }
        if (root->right && root->right->data == 1) {
            delete_all_nodes(root->right->left);
            root->right = root->right->right;
        }
    }
}

void BTree::del1() {
    del1_subtree(root);
}
