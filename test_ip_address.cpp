#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tuple>
#include "gtest/gtest.h"

// Структура для хранения IP-адреса
struct IPAddress {
    int n1, n2, n3, n4;

    // Конструктор для получения IP-адреса из строки
    IPAddress(const std::string& ipString) {
        std::stringstream ss(ipString);
        char dot;
        ss >> n1 >> dot >> n2 >> dot >> n3 >> dot >> n4;
    }

    // Метод для получения строкового представления IP-адреса
    std::string toString() const {
        return std::to_string(n1) + "." + std::to_string(n2) + "." + std::to_string(n3) + "." + std::to_string(n4);
    }
};

// Сравнение IP-адресов в обратном лексикографическом порядке
auto compareIP = [](const IPAddress& lhs, const IPAddress& rhs) {
    return std::tie(lhs.n1, lhs.n2, lhs.n3, lhs.n4) > std::tie(rhs.n1, rhs.n2, rhs.n3, rhs.n4);
};

// Тестовый файл с IP-адресами
const std::string TEST_FILE = "ip_filter.tsv";

// Функция для чтения IP-адресов из файла
std::vector<IPAddress> readIPAddressesFromFile(const std::string& filename) {
    std::vector<IPAddress> ipAddresses;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return ipAddresses;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string ipString;
        std::getline(ss, ipString, '\t'); // Чтение только первого поля
        ipAddresses.push_back(IPAddress(ipString));
    }
    file.close();
    return ipAddresses;
}

// Тесты
TEST(IPAddressTest, TestToString) {
    IPAddress ip("192.168.1.1");
    ASSERT_EQ(ip.toString(), "192.168.1.1");
}

TEST(IPAddressTest, TestSort) {
    std::vector<IPAddress> ipAddresses = readIPAddressesFromFile(TEST_FILE);
    std::sort(ipAddresses.begin(), ipAddresses.end(), compareIP);

    // Проверка порядка сортировки
    ASSERT_EQ(ipAddresses[0].toString(), "255.255.255.255");
    ASSERT_EQ(ipAddresses[1].toString(), "255.255.255.254");
    ASSERT_EQ(ipAddresses[2].toString(), "255.255.255.253");
}

TEST(IPAddressTest, TestFilterByFirstByte) {
    std::vector<IPAddress> ipAddresses = readIPAddressesFromFile(TEST_FILE);
    std::sort(ipAddresses.begin(), ipAddresses.end(), compareIP);

    std::vector<IPAddress> filteredAddresses;
    for (const auto& ip : ipAddresses) {
        if (ip.n1 == 1) {
            filteredAddresses.push_back(ip);
        }
    }

    // Проверка наличия IP-адресов с первым байтом 1
    ASSERT_NE(filteredAddresses.empty(), true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}