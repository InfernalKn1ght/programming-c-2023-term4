// sites.google.com/view/lebedins
#include <iostream>
#include <vector>

void del(std::vector<int> &v) {
    for (std::vector<int>::iterator i = v.begin(); i < v.end(); ++i) {
        i = v.erase(i);
    }
}

int main(int argc, char *argv[]) {
    std::vector<int> v = {1, 2, 4, 3, 6, 9, 8};

    del(v);

    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        std::cout << *i << " ";
    }
    return EXIT_SUCCESS;
}