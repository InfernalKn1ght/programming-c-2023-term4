#include <iostream>

class Queue {
private:
    int *data;
    int front;
    int back;
    int len;

    void expand() {
        int *temp = new int[len * 2];
        for (int i = 0; i < len; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        len *= 2;
    }

public:
    bool isEmpty() { return back == front; }

    int GetSize() { return len; }

    void PushBack(int key) {
        if (isEmpty()) {
            data[back] = key;
        } else {
            if (back >= len) {
                expand();
            }
            data[back] = key;
        }
        ++back;
    }

    void PopFront() {
        if (!isEmpty()) {
            ++front;
        }
    }

    int GetFront() {
        if (!isEmpty())
            return data[front];
        else
            return -1;
    }

    Queue(int len = 4) : data(new int[len]), front(0), back(front), len(len) {}

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

    q.PushBack(9);

    std::cout << q.GetFront() << "\n";
    q.PopFront();
    std::cout << q.GetFront() << "\n";

    return EXIT_SUCCESS;
}