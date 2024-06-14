#include "stree.cpp"
#include <iostream>

int main(int argc, char *argv[]) {
    SNode<int, int> *p9 = new SNode<int, int>(13, 130),
                    *p8 = new SNode<int, int>(7, 70),
                    *p7 = new SNode<int, int>(4, 40),
                    *p6 = new SNode<int, int>(14, 140, p9),
                    *p5 = new SNode<int, int>(6, 60, p7, p8),
                    *p4 = new SNode<int, int>(1, 10),
                    *p3 = new SNode<int, int>(10, 100, nullptr, p6),
                    *p2 = new SNode<int, int>(3, 30, p4, p5),
                    *p1 = new SNode<int, int>(8, 80, p2, p3);
    STree<int, int> t(p1);
    t.print();

    std::cout << t.find(8)->data << std::endl;

    std::cout << t.find_recursive(8)->data << std::endl;

    t.insert(15, 999);
    t.print();
    t.insert_recursive(9, 1000);
    t.print();
    t.del_node(8);
    std::cout << std::endl;
    t.print();

    return EXIT_SUCCESS;
}