#include <iostream>
#include <vector>

std::vector<int> concat(std::vector<int> &v1, std::vector<int> &v2) {
    std::vector<int> result(v1.size() + v2.size());
    std::copy(v1.begin(), v1.end(), result.begin());
    std::copy(v2.begin(), v2.end(), result.begin() + v1.size());

    return result;
}

int main(int argc, char *argv[]) {
    std::vector<int> v1 = {1, 2, 4, 3, 6, 9, 8};
    std::vector<int> v2 = {10, 22, 44, 13, 46, 79, 98};
    
    std::vector<int> result = concat(v1, v2);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return EXIT_SUCCESS;
}