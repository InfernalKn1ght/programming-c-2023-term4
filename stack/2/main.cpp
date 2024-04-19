#include <iostream>

struct Node {
    int data;
    Node *next;

    Node() : next(nullptr) {}
};

class Stack {
private:
    Node *root;
    int len;

public:
    bool isEmpty() { return len == 0; }

    void Push(int key) {
        ++len;

        if (len == 0) {
            root->data = key;
            root->next = nullptr;
            return;
        }

        Node *temp = root;
        root = new Node;
        root->data = key;
        root->next = temp;
    }

    void Pop() {
        if (!isEmpty()) {
            --len;
            Node *temp = root;
            root = root->next;

            delete temp;
        }
    }

    int getTop() {
        if (!isEmpty()) {
            return root->data;
        } else {
            return -1;
        }
    }

    Stack() : root(new Node), len(0) {}
    ~Stack() {
        if (len == 0) {
            delete root;
        } else {
            while (root) {
                Node* temp = root;
                root = root->next;
                delete temp; 
            }
        }
    }
};

int main(int argc, char *argv[]) {

    Stack s;
    s.Push(5);
    s.Push(6);
    s.Push(3);
    std::cout << s.getTop() << std::endl;
    s.Pop();
    std::cout << s.getTop() << std::endl;
    s.Pop();
    std::cout << s.getTop() << std::endl;
    s.Pop();
    std::cout << s.getTop() << std::endl;
    s.Pop();
    std::cout << s.getTop() << std::endl;
    s.Push(9);
    std::cout << s.getTop() << std::endl;

    return EXIT_SUCCESS;
}