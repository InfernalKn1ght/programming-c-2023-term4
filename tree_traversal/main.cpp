#include "BTree.cpp"
#include <iostream>

int main(int argc, char *argv[]) {
    BTree tree;

    tree.add(7);
    tree.add(-4);
    tree.add(6);
    tree.add(-10);
    tree.add(-3);
    tree.add(8);
    tree.add(12);
    tree.add(-15);
    tree.add(18);
    tree.add(11);

    tree.printRoot();

    std::cout << std::endl;

    // tree.rotateLeftRoot();

    std::cout << tree.sum() << " " << tree.count_neg() << " " << tree.height() << " " << tree.mult();

    std::cout << std::endl;

    tree.printRoot();
    tree.reflect();
    tree.printRoot();

    Node *n7 = new Node(14);
    Node *n6 = new Node(11);
    Node *n5 = new Node(10);
    Node *n4 = new Node(9);
    Node *n3 = new Node(2);
    n3->left = n6;
    n3->right = n7;
    Node *n2 = new Node(0);
    n2->left = n4;
    n2->right = n5;
    Node *n1 = new Node(1);
    n1->left = n2;
    n1->right = n3;

    BTree tree1(n1);
    tree1.printRoot();

    // std::cout << tree1.eval() << std::endl << tree.min() << " " << tree1.min();

    tree1.printRoot();
    // tree1.del0();
    // tree1.printRoot();
    tree1.del_leaves();
    tree1.printRoot();
    tree1.enlarge(1);
    tree1.printRoot();
    tree1.del1();
    tree1.printRoot();
    return EXIT_SUCCESS;
}