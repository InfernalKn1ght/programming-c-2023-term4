#include <iostream>

struct Node {
    int key;
    Node *next;

    Node(int key = 0) : key(key), next(nullptr) {}
};

class Queue {
private:
    Node *front;
    Node *back;
    int len;

public:
    bool isEmpty() { return len == 0; }

    int GetSize() { return len; }

    void PushBack(int key) {
        if (isEmpty())
            front->key = key;
        else {
            back->next = new Node(key);
            back = back->next;
        }
        ++len;
    }

    void PopFront() {
        if (len > 1) {
            Node *temp = front->next;

            delete front;
            front = temp;
            --len;
        } else if (len == 1) {
            delete front;
            front = new Node;
            back = front;
            --len;
        }
    }

    int GetFront() {
        if (len > 0)
            return front->key;
        else
            return -1;
    }

    Queue(int len = 0) : front(new Node), back(front), len(len) {}

    ~Queue() {}
};

int main(int argc, char *argv[]) {
    Queue q;

    q.PushBack(3);
    q.PushBack(5);

    std::cout << q.GetFront() << "\n";
    q.PopFront();

    std::cout << q.GetFront() << "\n";
    q.PopFront();

    std::cout << q.GetFront() << "\n";
    q.PopFront();

    return EXIT_SUCCESS;
}