#pragma once
#include <iostream>

template <class K, class T>
struct SNode {
    K key;
    T data;
    SNode<K, T> *left, *right;
    SNode(K k, T d, SNode<K, T> *l = nullptr, SNode<K, T> *r = nullptr) : key(k), data(d), left(l), right(r) {}
};

template <class K, class T>
struct STree {
    SNode<K, T> *root;
    STree<K, T>(SNode<K, T> *p) : root(p) {}

    void print();
    SNode<K, T> *find_subtree(SNode<K, T> *root, K key);
    SNode<K, T> *find(K key);
    SNode<K, T> *find_recursive_subtree(SNode<K, T> *root, K key);
    SNode<K, T> *find_recursive(K key);
    void insert_subtree(SNode<K, T> *root, K key, T data);
    void insert(K key, T data);
    void insert_recursive_subtree(SNode<K, T> *&root, K key, T data);
    void insert_recursive(K key, T data);
    void del_node_subtree(K key, SNode<K, T> *root);
    void del_node(K key);
    SNode<K, T> *get_parent(K key);
};
