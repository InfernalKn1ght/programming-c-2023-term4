#include "stree.h"

template <class K, class T>
void f_print(SNode<K, T> *r, int d = 0) {
    if (r == nullptr) {
        return;
    }

    f_print(r->right, d + 3);

    for (int i = 0; i < d; i++) {
        std::cout << " ";
    }
    std::cout << r->key << "(" << r->data << ")" << std::endl;
    f_print(r->left, d + 3);
}

template <class K, class T>
void STree<K, T>::print() {
    f_print(root);
}

template <class K, class T>
SNode<K, T> *STree<K, T>::find_subtree(SNode<K, T> *root, K key) {
    while (root) {
        if (root->key < key) {
            root = root->right;
        } else if (root->key > key) {
            root = root->left;
        } else {
            break;
        }
    }
    return root;
}

template <class K, class T>
SNode<K, T> *STree<K, T>::find(K key) {
    return find_subtree(root, key);
}

template <class K, class T>
SNode<K, T> *STree<K, T>::find_recursive_subtree(SNode<K, T> *root, K key) {
    if (!root) {
        return nullptr;
    }

    if (root->key < key) {
        return find_recursive_subtree(root->right, key);
    } else if (root->key > key) {
        return find_recursive_subtree(root->left, key);
    } else {
        return root;
    }
}

template <class K, class T>
SNode<K, T> *STree<K, T>::find_recursive(K key) {
    return find_recursive_subtree(root, key);
}

template <class K, class T>
void STree<K, T>::insert_subtree(SNode<K, T> *root, K key, T data) {
    if (find(key)) {
        return;
    }

    while (root) {
        if (root->key < key) {
            if (!root->right) {
                root->right = new SNode<K, T>(key, data);
                return;
            }
            root = root->right;
        }
        if (root->key > key) {
            if (!root->left) {
                root->left = new SNode<K, T>(key, data);
                return;
            }
            root = root->left;
        }
    }
}

template <class K, class T>
void STree<K, T>::insert(K key, T data) {
    insert_subtree(root, key, data);
}

template <class K, class T>
void STree<K, T>::insert_recursive_subtree(SNode<K, T> *&root, K key, T data) {
    if (!root) {
        root = new SNode<K, T>(key, data);
    }

    if (root->key < key) {
        insert_recursive_subtree(root->right, key, data);
    } else if (root->key > key) {
        insert_recursive_subtree(root->left, key, data);
    } else {
        return;
    }
}

template <class K, class T>
void STree<K, T>::insert_recursive(K key, T data) {
    insert_recursive_subtree(root, key, data);
}

template <class K, class T>
SNode<K, T> *find_next(SNode<K, T> *root) {
    if (!root->left) {
        return root;
    } else {
        return find_next(root->left);
    }
}

template <class K, class T>
SNode<K, T> *get_parent_subtree(SNode<K, T> *root, K key) {
    if (!root) {
        return nullptr;
    }

    if (root->right && root->right->key == key) {
        return root;
    }
    if (root->left && root->left->key == key) {
        return root;
    }
    if (root->key == key) {
        return root;
    }

    if (root->key < key) {
        return get_parent_subtree(root->right, key);
    } else if (root->key > key) {
        return get_parent_subtree(root->left, key);
    }
}

template <class K, class T>
SNode<K, T> *STree<K, T>::get_parent(K key) {
    return get_parent_subtree(root, key);
}


template <class K, class T>
void STree<K, T>::del_node_subtree(K key, SNode<K, T> *root) {
    SNode<K, T> *parent = get_parent(key);
    SNode<K, T> *node;
    if (parent->left->key == key) {
        node = parent->left;
    } else if (parent->right->key == key) {
        node = parent->right;
    } else {
        node = parent;
    }
    if (node->left != nullptr || node->right != nullptr) {
        SNode<K, T> *next = find_next(node->right);
        del_node(next->key);
        node->key = next->key;
        node->data = next->data;
    } else {
        if (parent->left->key == key) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
    }
}

template <class K, class T>
void STree<K, T>::del_node(K key) {
    del_node_subtree(key, root);
}