#include <iostream>
#include <string>

bool f(std::string &ip) {
    int c = 0;
    int j = ip.find_first_of('.');
    int start = 0;

    while (j != std::string::npos) {
        ++c;

        std::string s = ip.substr(start, j - start);
        std::cout << s << std::endl;
        int num = std::stoi(s);

        if (num > 255 || num < 0) {
            return 0;
        }

        start = j + 1;
        j = ip.find_first_of('.', j + 1);
    }

    int num = std::stoi(ip.substr(start));

    if (num <= 255 && num >= 0 && c == 3) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    std::string address = {"121..10.44.122"};

    std::cout << f(address);

    return EXIT_SUCCESS;
}