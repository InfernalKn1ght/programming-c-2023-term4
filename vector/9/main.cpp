#include <algorithm>
#include <iostream>
#include <vector>

int f(int n, std::vector<int> v) {
    std::vector<int>::iterator i = std::upper_bound(v.begin(), v.end(), n);
    if (i != v.begin() && *(i - 1) != n) {
        return -1;
    }

    return std::distance(v.begin(), i - 1);
}

int main(int argc, char *argv[]) {
    std::vector<int> v = {1, 2, 4, 5, 5, 5, 12, 22, 22};
    
    std::cout << f(5, v);

    return EXIT_SUCCESS;
}