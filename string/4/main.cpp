#include <iostream>
#include <string>

std::string f(std::string &str) {
    std::string new_str = "";
    int start = str.find_first_of('{');
    int end = str.find_first_of('}');
    std::string start_str = str.substr(0, start);
    std::string end_str = str.substr(end + 1);

    int j = str.find_first_of(',', start);
    while (j != std::string::npos) {
        new_str += start_str + str.substr(start + 1, j - start - 1) + end_str + ",";
        start = j;
        j = str.find_first_of(',', j + 1);
    }

    new_str += start_str + str.substr(start + 1, end - start - 1) + end_str;

    return new_str;
}

int main(int argc, char* argv[]) {
    std::string str = {"abc{def,gh,ijkl,189,pe}mn"};

    std::cout << f(str);

    return EXIT_SUCCESS;
}