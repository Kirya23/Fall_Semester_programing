#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#ifndef SOMETHING_H
#define SOMETHINNG_H

int main();
struct IPAddress {
    int n1, n2, n3, n4;

    // Конструктор для получения IP-адреса из строки
    IPAddress(const string& ipString) {
        stringstream ss(ipString);
        char dot;
        ss >> n1 >> dot >> n2 >> dot >> n3 >> dot >> n4;
    }

    // Метод для получения строкового представления IP-адреса
    string toString() const {
        return to_string(n1) + "." + to_string(n2) + "." + to_string(n3) + "." + to_string(n4);
    }
};
auto compareIP = [](const IPAddress& lhs, const IPAddress& rhs) {
    return tie(lhs.n1, lhs.n2, lhs.n3, lhs.n4) > tie(rhs.n1, rhs.n2, rhs.n3, rhs.n4);
};
#endif