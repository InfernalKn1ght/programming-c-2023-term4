#include <iostream>
#include <string>

void f(std::string &str, std::string &substr) {
    int j = str.find(substr);
    while (j != std::string::npos) {
        str.insert(j + substr.size(), ")");
        str.insert(j, "(");
        j = str.find(substr, j + substr.size());
    }
}

int main(int argc, char* argv[]) {
    std::string str = {"ertabcsdftyuabczevbh"};
    std::string substr = {"abc"};
    f(str, substr);
    std::cout << str;

    return EXIT_SUCCESS;
}