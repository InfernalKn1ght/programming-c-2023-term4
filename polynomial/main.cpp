#include <cmath>
#include <fstream>
#include <initializer_list>
#include <iostream>

class Polynomial {
private:
    int power;
    int *arr;

public:
    int &coef(int m) {
        static int error = -1;
        if (m < 0 || m > power) {
            return error;
        }
        return arr[m];
    }

    int value(int x) {
        int val = 0;
        for (int i = 0; i <= power; ++i) {
            val += std::pow(x, i) * arr[i];
        }
        return val;
    }

    Polynomial() : power(0), arr(new int[1]) {
        arr[0] = 0;
    }
    Polynomial(int power, int *arr) : power(power) {
        this->arr = new int[power + 1];
        for (int i = 0; i <= power; ++i) {
            this->arr[i] = arr[i];
        }
    }

    Polynomial(const Polynomial &p) {
        power = p.power;
        this->arr = new int[p.power + 1];
        for (int i = 0; i <= p.power; ++i) {
            this->arr[i] = p.arr[i];
        }
    }
    Polynomial(int x) : power(0), arr(new int[1]) {
        arr[0] = x;
    }
    Polynomial(const std::initializer_list<int> &list) : power(list.size() - 1), arr(new int[list.size()]) {
        std::copy(list.begin(), list.end(), arr);
    }

    ~Polynomial() {
        delete[] arr;
    }

    friend Polynomial operator+(Polynomial &a, Polynomial &b);
    friend Polynomial operator-(Polynomial &a, Polynomial &b);
    Polynomial &operator=(const Polynomial &a) {
        if (this == &a) {
            return *this;
        }
        if (this->power < a.power) {
            delete[] this->arr;
            this->arr = new int[a.power + 1];
        }
        this->power = a.power;
        for (int i = 0; i <= a.power; ++i) {
            this->arr[i] = a.arr[i];
        }
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &stream, Polynomial &a);
    friend std::istream &operator>>(std::istream &stream, Polynomial &a);
    friend Polynomial operator*(Polynomial &a, Polynomial &b);

    int &operator[](int i) {
        static int error = -1;
        if (i >= 0 && i <= this->power) {
            return arr[i];
        } else {
            return error;
        }
    }
};

Polynomial operator+(Polynomial &a, Polynomial &b) {
    int new_power = std::max(a.power, b.power);
    int *new_arr = new int[new_power + 1]{0};
    for (int i = 0; i <= std::max(a.power, b.power); ++i) {
        if (i <= a.power) {
            new_arr[i] += a.arr[i];
        }
        if (i <= b.power) {
            new_arr[i] += b.arr[i];
        }
    }

    return Polynomial(new_power, new_arr);
}

Polynomial operator-(Polynomial &a, Polynomial &b) {
    int new_power = std::max(a.power, b.power);
    int *new_arr = new int[new_power + 1]{0};
    for (int i = 0; i <= std::max(a.power, b.power); ++i) {
        if (i <= a.power) {
            new_arr[i] += a.arr[i];
        }
        if (i <= b.power) {
            new_arr[i] -= b.arr[i];
        }
    }

    return Polynomial(new_power, new_arr);
}

Polynomial operator*(Polynomial &a, Polynomial &b) {
    int new_power = a.power + b.power;
    int *new_arr = new int[new_power + 1]{0};
    for (int i = 0; i <= a.power; ++i) {
        for (int j = 0; j <= b.power; ++j) {
            new_arr[i + j] += a.arr[i] * b.arr[j];
        }
    }

    return Polynomial(new_power, new_arr);
}

std::ostream &operator<<(std::ostream &stream, Polynomial &a) {
    stream << "power: " << a.power << std::endl;
    for (int i = 0; i <= a.power; ++i) {
        if (a.arr[i] != 0) {
            stream << a.arr[i];
            if (i > 0) {
                stream << "x^" << i;
            }
            if (i < a.power) {
                stream << " + ";
            }
        }
    }

    stream << std::endl;

    return stream;
}

std::istream &operator>>(std::istream &stream, Polynomial &a) {
    int new_power = 0;
    stream >> new_power;

    if (a.power < new_power) {
        delete[] a.arr;
        a.arr = new int[new_power + 1];
    }
    a.power = new_power;
    for (int i = 0; i <= a.power; ++i) {
        stream >> a.arr[i];
    }

    return stream;
}

int main(int argc, char *argv[]) {

    int *arr1 = new int[3];
    int *arr2 = new int[3];

    arr2[0] = 1;
    arr2[1] = 2;
    arr2[2] = 1;
    arr2[3] = 1;

    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 1;

    Polynomial p(2, arr1);
    Polynomial p1(3, arr2);
    Polynomial p2 = p1 + p;
    Polynomial p3 = p1 - p;

    std::cout << p.coef(2) << " " << p.value(5) << std::endl;

    std::cout << p1.coef(1) << " " << p1.value(5) << std::endl;

    std::cout << p;

    std::cin >> p2;

    p2 = p2 * p;

    std::cout << p2;

    Polynomial p4{1, 2, 3, 4};
    std::cout << p4;

    p4[0] = 100;
    std::cout << p4;

    return EXIT_SUCCESS;
}