#pragma once

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

class BTree {
private:
    Node *root;
    bool empty;

    Node *getLeftNode(Node *root);
    Node *&getLeftLeave(Node *&root);
    void print(Node *root, int indent);
    Node *getSecondLeave(Node *root, int *num);
    void rotateLeft(Node *&root);
    int sum_subtree(Node *root);
    int count_neg_subtree(Node *root);
    int height_subtree(Node *root);
    void reflect_subtree(Node *root);
    int mult_subtree(Node* root);
    int eval_subtree(Node* root);
    int min_subtree(Node* root);
    void del0_subtree(Node* root);
    void del_leaves_subtree(Node *&root);
    void enlarge_subtree(Node*& root, int d);
    void del1_subtree(Node*& root);

public:
    Node *getLeftNodeRoot();
    void rotateLeftRoot();
    Node *getLeftGrandsonRoot();
    Node *&getLeftLeaveRoot();
    void removeLeftLeave();
    void add(int data);
    void printRoot();
    Node *getSecondLeaveRoot();
    int sum();
    int count_neg();
    int height();
    void reflect();
    int mult();
    int eval();
    int min();
    void del0();
    void del_leaves();
    void enlarge(int d);
    void del1();

    BTree(Node* root = new Node) : root(root), empty(1) {}
};
