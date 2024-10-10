#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <tuple>
#include <cstdint>

using namespace std;

// Структура для хранения IP-адреса
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

// Сравнение IP-адресов в обратном лексикографическом порядке
auto compareIP = [](const IPAddress& lhs, const IPAddress& rhs) {
    return tie(lhs.n1, lhs.n2, lhs.n3, lhs.n4) > tie(rhs.n1, rhs.n2, rhs.n3, rhs.n4);
};

int main() {
    vector<IPAddress> ipAddresses;

    // Чтение IP-адресов из файла
    ifstream file("ip_filter.tsv");
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла ip_filter.tsv" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string ipString;
        getline(ss, ipString, '\t'); // Чтение только первого поля
        ipAddresses.push_back(ipString);
    }
   
    file.close();

    // Сортировка в обратном лексикографическом порядке
    sort(ipAddresses.begin(), ipAddresses.end(), compareIP);

    cout<< "Вывод всех IP-адресов"<< endl;
    for (const auto& ip : ipAddresses) {
        cout << ip.toString() << endl;
    }

    cout<< "Вывод IP-адресов с первым байтом 1"<< endl;
    for (const auto& ip : ipAddresses) {
        if (ip.n1 == 1) {
            cout << ip.toString() << endl;
        }
    }

    cout<<" Вывод IP-адресов с первым байтом 46 и вторым байтом 70"<< endl;
    for (const auto& ip : ipAddresses) {
        if (ip.n1 == 46 && ip.n2 == 70) {
            cout << ip.toString() << endl;
        }
    }

   cout<< "Вывод IP-адресов с любым байтом 46"<< endl;
    for (const auto& ip : ipAddresses) {
        if (ip.n1 == 46 || ip.n2 == 46 || ip.n3 == 46 || ip.n4 == 46) {
            cout << ip.toString() << endl;
        }
    }

    return 0;
}