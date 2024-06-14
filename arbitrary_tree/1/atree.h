#pragma once
#include <vector>
#include <iostream>

template <class T>
struct ANode {
    T data;
    ANode<T> *down, *right;
    ANode(T data, ANode<T> *down = nullptr, ANode<T> *right = nullptr) : data(data), down(down), right(right) {}
};

template <class T>
struct ATree {
    ANode<T> *root;
    
    ATree(ANode<T> *root) : root(root) {}

    void print();
    void add_first(T data);
    void del_first();
    int count_grandson();
    ANode<T> *find_d1(T d1, T d2); 
    ANode<T> *walk(std::vector<int> son_numbers);
    void remove_sons();
};
