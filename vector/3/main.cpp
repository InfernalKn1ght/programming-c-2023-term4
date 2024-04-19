#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> v = {1, 2, 4, 3, 6, 9, 8};
    int arr[7];

    std::copy(v.begin(), v.end(), arr);

    for (int i = 0; i < 7; ++i) {
        std::cout << arr[i] << " ";
    }

    return EXIT_SUCCESS;
}