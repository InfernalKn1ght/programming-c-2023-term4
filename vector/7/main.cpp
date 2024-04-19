#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int>::iterator second_occure(int n, std::vector<int> &v) {
    std::vector<int>::iterator i = std::find(v.begin(), v.end(), n);

    while (i != v.end()) {
        std::vector<int>::iterator j = std::find(i + 1, v.end(), n);
        if (j == v.end()) {
            break;
        }
        i = j;
    }

    return i;
}

int main(int argc, char *argv[]) {
    std::vector<int> v = {1, 2, 4, 5, 7, 6, 8, 9, 3, 4, 5};

    std::vector<int>::iterator i = second_occure(0, v);
    if (i != v.end()) {
        std::cout << *i;
    }

    return EXIT_SUCCESS;
}