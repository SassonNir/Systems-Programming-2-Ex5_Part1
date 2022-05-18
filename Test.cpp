#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "OrgChart.hpp"
#include "doctest.h"
using namespace std;
using namespace ariel;

TEST_CASE("Add Root") {
    OrgChart org;
    CHECK_THROWS(org.add_root(""));
    CHECK_NOTHROW(org.add_root("CEO"));
    for (auto x : org)
        CHECK_EQ(x.get_data(), "CEO");
    for (int i = 0; i < 5; i++)
        CHECK_NOTHROW(org.add_sub("CEO", "employee" + to_string(i)));
}
TEST_CASE("Add Sub") {
    OrgChart org;
    CHECK_NOTHROW(org.add_root("0"));
    for (int i = 0; i < 5; i++) {
        std::string root = "0";
        CHECK_NOTHROW(org.add_sub(root, root + "." + to_string(i)));
    }

    for (int i = 0; i < 5; i++) {
        std::string root = "0." + to_string(i);
        CHECK_NOTHROW(org.add_sub(root, root + "." + to_string(i)));
    }

    for (int i = 0; i < 5; i++) {
        std::string root = "0." + to_string(i) + "." + to_string(i);
        CHECK_NOTHROW(org.add_sub(root, root + "." + to_string(i)));
    }

    CHECK_THROWS(org.add_sub("0", ""));
    CHECK_THROWS(org.add_sub("", "0."));
    CHECK_THROWS(org.add_sub("", ""));
    for (int i = 0; i < 5; i++)
        CHECK_THROWS(org.add_sub("1", "1." + to_string(i)));
}
