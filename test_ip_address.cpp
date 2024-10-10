#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "main.cpp"

using namespace std;


TEST(IPAddressTest, ValidIPAddress) {
    IPAddress ip("192.168.0.1");
    EXPECT_EQ(ip.n1, 192);
    EXPECT_EQ(ip.n2, 168);
    EXPECT_EQ(ip.n3, 0);
    EXPECT_EQ(ip.n4, 1);
}

TEST(IPAddressTest, ToString) {
    IPAddress ip("10.0.0.5");
    EXPECT_EQ(ip.toString(), "10.0.0.5");
}

TEST(SortIPAddressesTest, SortsCorrectly) {
    std::vector<IPAddress> ips = {
        IPAddress("192.168.1.1"),
        IPAddress("10.0.0.1"),
        IPAddress("172.16.0.5")
    };

    sort(ips.begin(), ips.end(), compareIP);

    EXPECT_EQ(ips[0].toString(), "10.0.0.1");
    EXPECT_EQ(ips[1].toString(), "172.16.0.5");
    EXPECT_EQ(ips[2].toString(), "192.168.1.1");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}