#include <algorithm>
#include <iostream>
#include <vector>

bool subseq(std::vector<int> v, std::vector<int> sub_v) {
    std::vector<int>::iterator k = v.begin();
    for (int i = 0; i < sub_v.size(); ++i) {
        std::vector<int>::iterator j = find(k, v.end(), sub_v[i]);
        if (j == v.end()) {
            return 0;
        }
        k = j + 1;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> v1 = {3, 5, 7, 9};
    std::vector<int> v2 = {5, 3, 7, 8};

    std::cout << subseq(v, v1) << " " << subseq(v, v2);
    

    return EXIT_SUCCESS;
}