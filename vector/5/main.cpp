#include <iostream>
#include <vector>

std::vector<int> repeat(int n, std::vector<int> &v) {
    std::vector<int> result(v.size() * n);
    for (int i = 0; i < n; ++i) {
        std::copy(v.begin(), v.end(), result.begin() + v.size() * i);
    }

    return result;
}

int main(int argc, char *argv[]) {
    std::vector<int> v = {1, 2, 4};

    std::vector<int> result = repeat(3, v);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return EXIT_SUCCESS;
}