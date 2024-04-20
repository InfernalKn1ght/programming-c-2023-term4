#include <iostream>
#include <stack>
#include <string>

int f2() {
    char c;
    std::stack<int> s;
    std::cin.get(c);
    while (c != '\n') {
        if (isdigit(c)) {
            int n;
            std::cin.putback(c);
            std::cin >> n;
            s.push(n);
        } else {
            int temp;
            switch (c) {
            case '+':
                temp = s.top();
                s.pop();
                s.top() += temp;
                break;
            case '-':
                temp = s.top();
                s.pop();
                s.top() -= temp;
                break;
            case '*':
                temp = s.top();
                s.pop();
                s.top() *= temp;
                break;
            case '/':
                temp = s.top();
                s.pop();
                s.top() /= temp;
                break;
            default:
                break;
            }
        }
        std::cin.get(c);
    }

    return s.top();
}

void f1() {
    std::string out = "";

    std::stack<char> s;

    char c;

    std::cin.get(c);

    while (c != '\n') {
        if (isdigit(c)) {
            int n;
            std::cin.putback(c);
            std::cin >> n;
            out += std::to_string(n);
        } else {
            int temp;
            switch (c) {
            case '-':
            case '+':
                while (!s.empty()) {
                    if (s.top() != '(') {
                        out.push_back(s.top());
                        s.pop();
                    } else {
                        break;
                    }
                }
				s.push(c);
                break;
            case '*':
            case '/':
               while (!s.empty()) {
                    if (s.top() == '*' || s.top() == '/') {
                        out.push_back(s.top());
                        s.pop();
                    } else {
                        break;
                    }
                }
				s.push(c);
                break;
			case '(':
				s.push(c);
				break;
			case ')':
				while (s.top() != '(') {
					out.push_back(s.top());
					s.pop();
				}
				s.pop();
				break;
            default:
                break;
            }
        }
        std::cin.get(c);
    }

	while (!s.empty()) {
		out.push_back(s.top());
		s.pop();
	}

	std::cout << out;
}

int main(int argc, char *argv[]) {
    f1(); // 3 + 4 * 2 / (1 - 5)
    

    return EXIT_SUCCESS;
}