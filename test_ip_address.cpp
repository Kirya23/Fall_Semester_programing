#include "gtest/gtest.h"
#include "main.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <tuple>
#include <cstdint>

// Тестовый набор IP-адресов для проверки
vector<IPAddress> createTestIPAddresses() {
    vector<IPAddress> testAddresses = {
        IPAddress("192.168.1.1"),
        IPAddress("10.0.0.1"),
        IPAddress("172.16.0.1"),
        IPAddress("1.2.3.4"),
        IPAddress("46.70.1.2"),
        IPAddress("46.1.2.3"),
        IPAddress("192.168.46.1"),
        IPAddress("1.2.3.46")
    };
    return testAddresses;
}

TEST(IPFiltering, Sort) {
    vector<IPAddress> ipAddresses = createTestIPAddresses();
    sort(ipAddresses.begin(), ipAddresses.end(), compareIP);

    // Проверка, что адреса отсортированы в обратном лексикографическом порядке
    ASSERT_EQ(ipAddresses[0].toString(), "192.168.46.1");
    ASSERT_EQ(ipAddresses[1].toString(), "192.168.1.1");
    ASSERT_EQ(ipAddresses[2].toString(), "172.16.0.1");
    ASSERT_EQ(ipAddresses[3].toString(), "46.70.1.2");
    ASSERT_EQ(ipAddresses[4].toString(), "46.1.2.3");
    ASSERT_EQ(ipAddresses[5].toString(), "10.0.0.1");
    ASSERT_EQ(ipAddresses[6].toString(), "1.2.3.46");
    ASSERT_EQ(ipAddresses[7].toString(), "1.2.3.4");
}

TEST(IPFilteringTest, FilterFirstByte) {
    vector<IPAddress> ipAddresses = createTestIPAddresses();
    vector<string> filteredAddresses;

    for (const auto& ip : ipAddresses) {
        if (ip.n1 == 1) {
            filteredAddresses.push_back(ip.toString());
        }
    }

    // Проверка фильтрации по первому байту
    ASSERT_EQ(filteredAddresses.size(), 3);
    ASSERT_NE(find(filteredAddresses.begin(), filteredAddresses.end(), "192.168.1.1"), filteredAddresses.end());
    ASSERT_NE(find(filteredAddresses.begin(), filteredAddresses.end(), "1.2.3.4"), filteredAddresses.end());
    ASSERT_NE(find(filteredAddresses.begin(), filteredAddresses.end(), "1.2.3.46"), filteredAddresses.end());
}

TEST(IPFilteringTest, FilterAnyByte) {
    vector<IPAddress> ipAddresses = createTestIPAddresses();
    vector<string> filteredAddresses;

    for (const auto& ip : ipAddresses) {
        if (ip.n1 == 46 || ip.n2 == 46 || ip.n3 == 46 || ip.n4 == 46) {
            filteredAddresses.push_back(ip.toString());
        }
    }

    // Проверка фильтрации по любому байту
    ASSERT_EQ(filteredAddresses.size(), 4);
    ASSERT_NE(find(filteredAddresses.begin(), filteredAddresses.end(), "46.70.1.2"), filteredAddresses.end());
    ASSERT_NE(find(filteredAddresses.begin(), filteredAddresses.end(), "46.1.2.3"), filteredAddresses.end());
    ASSERT_NE(find(filteredAddresses.begin(), filteredAddresses.end(), "192.168.46.1"), filteredAddresses.end());
    ASSERT_NE(find(filteredAddresses.begin(), filteredAddresses.end(), "1.2.3.46"), filteredAddresses.end());
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }