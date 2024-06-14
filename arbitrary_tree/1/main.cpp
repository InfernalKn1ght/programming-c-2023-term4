#include "atree.cpp"
#include <iostream>

int main(int argc, char *argv[]) {
    ANode<int> *p10 = new ANode<int>(10),
               *p9 = new ANode<int>(9, nullptr, p10),
               *p8 = new ANode<int>(8),
               *p7 = new ANode<int>(7),
               *p6 = new ANode<int>(6, nullptr, p7),
               *p5 = new ANode<int>(5, nullptr, p6),
               *p4 = new ANode<int>(4, p9),
               *p3 = new ANode<int>(3, p8, p4),
               *p2 = new ANode<int>(2, p5, p3),
               *p1 = new ANode<int>(1, p2);

    ATree<int> *tree1 = new ATree<int>(p1);

    tree1->print();
    tree1->del_first();
    tree1->print();
    tree1->add_first(11);
    tree1->print();
    std::cout << std::endl << tree1->count_grandson();
    std::cout << std::endl << tree1->find_d1(4, 11);

    std::vector<int> v = {6, 2};

    std::cout << std::endl << tree1->walk(v) << std::endl;

    tree1->print();
    tree1->remove_sons();
    tree1->print();
    
    return EXIT_SUCCESS;
}