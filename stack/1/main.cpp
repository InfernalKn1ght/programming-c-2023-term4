#include <iostream>

class Stack {
private:
    int *data;
    int top;
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

    bool validLen() { return top < len; }

public:
    bool isEmpty() { return top == 0; }

    void Push(int key) {
        if (!validLen()) {
            expand();
        }

        data[top] = key;
        top++;
    }

    void Pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    int getTop() {
        if (!isEmpty()) {
            return data[top - 1];
        } else {
            return -1;
        }
    }

    Stack(int len = 1) : data(new int[len]), top(0), len(len) {}
    ~Stack() { delete[] data; }
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