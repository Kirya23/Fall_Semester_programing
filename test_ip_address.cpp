#include <gtest/gtest.h>
#include <boost/test/unit_test.hpp>
#include "main.h"
using namespace std;

BOOST_AUTO_TEST_SUITE(IPAddress_Test)

BOOST_AUTO_TEST_CASE(test_ip_address_constructor) {
    IPAddress ip("192.168.1.1");
    BOOST_CHECK_EQUAL(ip.n1, 192);
    BOOST_CHECK_EQUAL(ip.n2, 168);
    BOOST_CHECK_EQUAL(ip.n3, 1);
    BOOST_CHECK_EQUAL(ip.n4, 1);
}

BOOST_AUTO_TEST_CASE(test_ip_address_to_string) {
    IPAddress ip("192.168.1.1");
    BOOST_CHECK_EQUAL(ip.toString(), "192.168.1.1");
}

BOOST_AUTO_TEST_CASE(test_compare_ip_addresses) {
    IPAddress ip1("192.168.1.1");
    IPAddress ip2("192.168.1.2");
    BOOST_CHECK(compareIP(ip1, ip2));
    BOOST_CHECK(!compareIP(ip2, ip1));
}

BOOST_AUTO_TEST_SUITE_END()

