#include <algorithm>
#include <iostream>
#include <vector>

void f(std::vector<double> &v, double x, int &i, int &j) {
    std::vector<double>::iterator start = std::lower_bound(v.begin(), v.end(), x);
    std::vector<double>::iterator end = std::upper_bound(v.begin(), v.end(), x);

    i = std::distance(v.begin(), start);
    j = std::distance(v.begin(), end);

    if (*start != x) {
        --i;
    }

    if (*(end - 1) == x) {
        --j;
    }
}

int main(int argc, char *argv[]) {
    std::vector<double> v = {4, 4.32, 7.314, 10.5, 15.8, 19.21, 23.5, 28.34};

    int i = 0;
    int j = 0;

    f(v, 29, i, j);

    std::cout << i << " " << j;

    return EXIT_SUCCESS;
}