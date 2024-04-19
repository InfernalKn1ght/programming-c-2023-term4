#include <iostream>
#include <string>

void f(std::string &str) {
    int left = 0;
    int right = 0;
    int middle = 0;

    middle = str.find_first_of('+');
    while (middle != std::string::npos) {
        left = middle - 1;
        while (str[left] - '0' >= 0 && str[left] - '0' < 10) {
            --left;
        }
        ++left;

        right = middle + 1;
        while (str[right] - '0' >= 0 && str[right] - '0' < 10) {
            ++right;
        }
        --right;

        int num = 0;
        if (left != middle && right != middle) {
            num = std::stoi(str.substr(left, middle - left)) + std::stoi(str.substr(middle + 1, right - middle));

            str.erase(left, right - left + 1);
            str.insert(left, std::to_string(num));
            middle = str.find_first_of('+');
        } else {
            middle = str.find_first_of('+', middle + 1);
        }
    }
}

int main(int argc, char *argv[]) {
    std::string str = {"5+g26-72+35gh32+45+12"};
    f(str);
    std::cout << str;

    return EXIT_SUCCESS;
}