// sites.google.com/view/lebedins
#include <iostream>
#include <vector>

void enlarge(std::vector<double> &v) {
    for (std::vector<double>::iterator i = v.begin() + 1; i != v.end(); ++i) {
        i = v.insert(i, (*i + *(i - 1)) / 2.0);
        ++i;
    }
}

int main(int argc, char *argv[]) {
    std::vector<double> v = {1, 2, 4, 3, 6, 9, 8};

    enlarge(v);

    for (std::vector<double>::iterator i = v.begin(); i != v.end(); ++i) {
        std::cout << *i << " ";
    }
    return EXIT_SUCCESS;
}