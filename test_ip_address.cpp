#include <gtest/gtest.h>
#include "mian.h"  // Замените на фактический путь к вашему заголовочному файлу

// Тест для конструктора IPAddress
TEST(IPAddressTest, ValidIP) {
    IPAddress ip("192.168.0.1");
    EXPECT_EQ(ip.n1, 192);
    EXPECT_EQ(ip.n2, 168);
    EXPECT_EQ(ip.n3, 0);
    EXPECT_EQ(ip.n4, 1);
}

TEST(IPAddressTest, InvalidIP) {
    EXPECT_THROW(IPAddress("256.168.0.1"), invalid_argument);
    EXPECT_THROW(IPAddress("192.168.300.1"), invalid_argument);
    EXPECT_THROW(IPAddress("192.168.0.-1"), invalid_argument);
}

// Тест для функции чтения IP-адресов из файла
TEST(ReadIPAddressesFromFileTest, ValidFile) {
    auto ips = readIPAddressesFromFile("valid_ip_filter.tsv");
    EXPECT_EQ(ips.size(), 3);  // Замените на актуальное количество адресов в файле
    EXPECT_EQ(ips[0].toString(), "192.168.1.1");
}

TEST(ReadIPAddressesFromFileTest, InvalidFile) {
    EXPECT_THROW(readIPAddressesFromFile("invalid_file.tsv"), runtime_error);
}