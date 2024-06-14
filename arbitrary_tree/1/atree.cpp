#include "atree.h"

template <class T>
void print_tree(ANode<T> *root, int space = 0) {
    if (root == nullptr) {
        return;
    }
    for (int i = 0; i < space; i++) {
        std::cout << '\t';
    }

    std::cout << root->data << std::endl;

    print_tree(root->down, space + 1);
    print_tree(root->right, space);
}

template <class T>
int count(ANode<T> *root) {
    int c = 0;
    if (root == nullptr) {
        return c;
    }

    root = root->down;

    while (root != nullptr) {
        ++c;
        root = root->right;
    }

    return c;
}

template <class T>
void ATree<T>::print() {
    print_tree(root);
}

template <class T>
void ATree<T>::add_first(T data) {
    ANode<T> *t;
    t = new ANode<T>(data, nullptr, root->down);
    root->down = t;
}

template <class T>
void ATree<T>::del_first() {
    ANode<T> *t1 = root->down;
    ANode<T> *t2 = t1->down;
    ANode<T> *t = t2;

    while (t->right) {
        t = t->right;
    }

    t->right = t1->right;
    root->down = t2;
    delete t1;
}

template <class T>
int ATree<T>::count_grandson() {
    int c = 0;
    if (root) {
        ANode<T> *temp = root->down;
        while (temp) {
            c += count(temp);
            temp = temp->right;
        }
    }
    return c;
}

template <class T>
ANode<T> *ATree<T>::find_d1(T d1, T d2) {
    if (root) {
        ANode<T> *temp = root->down;
        while (temp) {
            if (temp->data == d1) {
                ANode<T> *temp1 = temp->down;
                while (temp1) {
                    if (temp1->data == d2) {
                        return temp1;
                    }
                    temp1 = temp1->right;
                }
            }
            temp = temp->right;
        }
    }
    return nullptr;
}

template <class T>
ANode<T> *ATree<T>::walk(std::vector<int> son_numbers) {
    if (root) {
        ANode<T> *prev = root;
        for (int i = 0; i < son_numbers.size(); ++i) {
            ANode<T> *temp = prev->down;
            for (int j = 0; j < son_numbers[i] - 1; ++j) {
                if (temp) {
                    temp = temp->right;
                } else {
                    return nullptr;
                }
            }
            prev = temp;
        }
        return prev;
    }
    return nullptr;
}

template <class T>
void ATree<T>::remove_sons() {
    if (root) {
        ANode<T> *temp1 = root->down;
        ANode<T> *new_down = nullptr;
        ANode<T> *remove_temp1 = temp1;

        while (temp1) {
            ANode<T> *temp2 = temp1->down;
            if (!new_down && temp2) {
                new_down = temp2;
            }
            if (temp2) {
                while (temp2->right) {
                    temp2 = temp2->right;
                }

                if (temp1->right && temp1->right->down) {
                    temp2->right = temp1->right->down;
                }
            }
            temp1 = temp1->right;
            delete remove_temp1;
            remove_temp1 = temp1;
        }

        root->down = new_down;
    }
}
