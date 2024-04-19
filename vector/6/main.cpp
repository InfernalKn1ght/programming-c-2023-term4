#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>::iterator second_occure(int n, std::vector<int> &v) {
    std::vector<int>::iterator i = std::find(v.begin(), v.end(), n);
    i = std::find(i + 1, v.end(), n);

    return i;
}

int main(int argc, char *argv[]) {
    std::vector<int> v = {99,99,3,2,3,10,4,4,4};

    std::vector<int>::iterator i = second_occure(99, v);
    
    if (i != v.end()) {
        std::cout << i - v.begin();;
    } else {
        std::cout << "!";
    }

    return EXIT_SUCCESS;
}