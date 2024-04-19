#include <cmath>
#include <fstream>
#include <initializer_list>
#include <iostream>

class Polynomial {
private:
    int power;
    int *arr;

public:
    int &coef(int m) const {
        static int error = -1;
        if (m < 0 || m > power) {
            return error;
        }
        return arr[m];
    }

    int value(int x) const {
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
    Polynomial(Polynomial &&p) : power(p.power), arr(p.arr) {
        p.power = 0;
        p.arr = nullptr;
    }

    ~Polynomial() {
        delete[] arr;
    }

    Polynomial operator+(const Polynomial &a) const;
    Polynomial operator-(const Polynomial &a) const;
    Polynomial &operator=(Polynomial &&a);
    Polynomial &operator=(const Polynomial &a);
    Polynomial operator*(const Polynomial &a) const;
    friend std::ostream &operator<<(std::ostream &stream, const Polynomial &a);
    friend std::istream &operator>>(std::istream &stream, Polynomial &a);

    int &operator[](int i) {
        static int error = -1;
        if (i >= 0 && i <= this->power) {
            return arr[i];
        } else {
            return error;
        }
    }

    int operator()(const int x) const;
};

Polynomial &Polynomial::operator=(const Polynomial &a) {
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

Polynomial &Polynomial::operator=(Polynomial &&a) {
    if (this == &a) {
        return *this;
    }
    delete[] arr;
    power = a.power;
    arr = a.arr;

    a.power = 0;
    a.arr = nullptr;
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &a) const {
    int new_power = std::max(a.power, power);
    int *new_arr = new int[new_power + 1]{0};
    for (int i = 0; i <= std::max(a.power, power); ++i) {
        if (i <= a.power) {
            new_arr[i] += a.arr[i];
        }
        if (i <= power) {
            new_arr[i] += arr[i];
        }
    }

    return std::move(Polynomial(new_power, new_arr));
}

Polynomial Polynomial::operator-(const Polynomial &a) const {
    int new_power = std::max(a.power, power);
    int *new_arr = new int[new_power + 1]{0};
    for (int i = 0; i <= std::max(a.power, power); ++i) {
        if (i <= a.power) {
            new_arr[i] += a.arr[i];
        }
        if (i <= power) {
            new_arr[i] -= arr[i];
        }
    }

    return Polynomial(new_power, new_arr);
}

Polynomial Polynomial::operator*(const Polynomial &a) const {
    int new_power = a.power + power;
    int *new_arr = new int[new_power + 1]{0};
    for (int i = 0; i <= a.power; ++i) {
        for (int j = 0; j <= power; ++j) {
            new_arr[i + j] += a.arr[i] * arr[j];
        }
    }

    return Polynomial(new_power, new_arr);
}

std::ostream &operator<<(std::ostream &stream, const Polynomial &a) {
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

int Polynomial::operator()(const int x) const {
    int val = 0;
    for (int i = 0; i <= power; ++i) {
        val += std::pow(x, i) * arr[i];
    }
    return val;
}

int main(int argc, char *argv[]) {
    Polynomial a{1, 2, 1};
    Polynomial b;

    b = std::move(a);

    Polynomial c{1, 2, 1};
    Polynomial d{1, 3, 1};

    std::cout << (c + d);
    std::cout << (c * d);

    return EXIT_SUCCESS;
}