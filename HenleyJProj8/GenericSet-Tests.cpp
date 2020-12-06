// This is the collection of unit tests for the template class GenericSet
// Each TEST_CASE is for a GenericSet containing a different data type
// Test cases are included for types int, double, char, string, bool,
// and a GenericSet containing GenericSet<int> members
// Tests are written for the Catch2 test framework, a header-only testing framework for C++11 onwards
// testsMain.cpp is required to run the tests
// VERSION: 2020-04-21

#include "catch.hpp"
#include "GenericSet.h"

using namespace fhsuhenleyj;

TEST_CASE("Integer Set", "[GenericSet_lib]") {
    GenericSet<int> testSet;
    int m1 = 5, m2 = 10;

    // Tests the default constructor to make sure it creates an empty set
    SECTION("Constructor check"){
        CHECK(testSet.getSize() == 0);
        CHECK(!testSet.isMember(0));
    }

    // Tests the add() and isMember() functions of GenericSet
    SECTION("Adding Members and isMember"){
        CHECK(!testSet.isMember(m1));

        testSet.add(m1);
        CHECK(testSet.isMember(m1));
        CHECK(!testSet.isMember(m2));

        testSet.add(m2);
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 2);
    }

    // Tests the remove() function of GenericSet
    SECTION("Removing Members"){
        testSet.add(m1);
        testSet.add(m2);

        testSet.remove(m1);

        CHECK(!testSet.isMember(m1));
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 1);
    }

    // Tests the array export function
    SECTION("Export Array Test"){
        testSet.add(m1);
        testSet.add(m2);

        int* exportedArray;
        exportedArray = testSet.exportArray();

        CHECK(exportedArray[0] == m1);
        CHECK(exportedArray[1] == m2);

        delete [] exportedArray;
    }

}

TEST_CASE("Double Set", "[GenericSet_lib]") {
    GenericSet<double> testSet;
    double m1 = 5.5, m2 = 10.1;

    // Tests the default constructor to make sure it creates an empty set
    SECTION("Constructor check"){
        CHECK(testSet.getSize() == 0);
        CHECK(!testSet.isMember(0));
    }

    // Tests the add() and isMember() functions of GenericSet
    SECTION("Adding Members and isMember"){
        CHECK(!testSet.isMember(m1));

        testSet.add(m1);
        CHECK(testSet.isMember(m1));
        CHECK(!testSet.isMember(m2));

        testSet.add(m2);
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 2);
    }

    // Tests the remove() function of GenericSet
    SECTION("Removing Members"){
        testSet.add(m1);
        testSet.add(m2);

        testSet.remove(m1);

        CHECK(!testSet.isMember(m1));
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 1);
    }

    // Tests the array export function
    SECTION("Export Array Test"){
        testSet.add(m1);
        testSet.add(m2);

        double* exportedArray;
        exportedArray = testSet.exportArray();

        CHECK(exportedArray[0] == m1);
        CHECK(exportedArray[1] == m2);

        delete [] exportedArray;
    }
}

TEST_CASE("Char Set", "[GenericSet_lib]") {
    GenericSet<char> testSet;
    double m1 = 'a', m2 = 'Z';

    // Tests the default constructor to make sure it creates an empty set
    SECTION("Constructor check"){
        CHECK(testSet.getSize() == 0);
        CHECK(!testSet.isMember(0));
    }

        // Tests the add() and isMember() functions of GenericSet
    SECTION("Adding Members and isMember"){
        CHECK(!testSet.isMember(m1));

        testSet.add(m1);
        CHECK(testSet.isMember(m1));
        CHECK(!testSet.isMember(m2));

        testSet.add(m2);
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 2);
    }

        // Tests the remove() function of GenericSet
    SECTION("Removing Members"){
        testSet.add(m1);
        testSet.add(m2);

        testSet.remove(m1);

        CHECK(!testSet.isMember(m1));
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 1);
    }

        // Tests the array export function
    SECTION("Export Array Test"){
        testSet.add(m1);
        testSet.add(m2);

        char* exportedArray;
        exportedArray = testSet.exportArray();

        CHECK(exportedArray[0] == m1);
        CHECK(exportedArray[1] == m2);

        delete [] exportedArray;
    }
}

TEST_CASE("String Set", "[GenericSet_lib]") {
    #include <string>
    using namespace std;

    GenericSet<string> testSet;
    string m1 = "hello", m2 = "world";

    // Tests the default constructor to make sure it creates an empty set
    SECTION("Constructor check"){
        CHECK(testSet.getSize() == 0);
        CHECK(!testSet.isMember(""));
    }

        // Tests the add() and isMember() functions of GenericSet
    SECTION("Adding Members and isMember"){
        CHECK(!testSet.isMember(m1));

        testSet.add(m1);
        CHECK(testSet.isMember(m1));
        CHECK(!testSet.isMember(m2));

        testSet.add(m2);
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 2);
    }

        // Tests the remove() function of GenericSet
    SECTION("Removing Members"){
        testSet.add(m1);
        testSet.add(m2);

        testSet.remove(m1);

        CHECK(!testSet.isMember(m1));
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 1);
    }

        // Tests the array export function
    SECTION("Export Array Test"){
        testSet.add(m1);
        testSet.add(m2);

        string* exportedArray;
        exportedArray = testSet.exportArray();

        CHECK(exportedArray[0] == m1);
        CHECK(exportedArray[1] == m2);

        delete [] exportedArray;
    }
}

TEST_CASE("Bool Set", "[GenericSet_lib]") {
    GenericSet<bool> testSet;
    bool m1 = true, m2 = false;

    // Tests the default constructor to make sure it creates an empty set
    SECTION("Constructor check"){
        CHECK(testSet.getSize() == 0);
        CHECK(!testSet.isMember(0));
    }

        // Tests the add() and isMember() functions of GenericSet
    SECTION("Adding Members and isMember"){
        CHECK(!testSet.isMember(m1));

        testSet.add(m1);
        CHECK(testSet.isMember(m1));
        CHECK(!testSet.isMember(m2));

        testSet.add(m2);
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 2);
    }

        // Tests the remove() function of GenericSet
    SECTION("Removing Members"){
        testSet.add(m1);
        testSet.add(m2);

        testSet.remove(m1);

        CHECK(!testSet.isMember(m1));
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 1);
    }

        // Tests the array export function
    SECTION("Export Array Test"){
        testSet.add(m1);
        testSet.add(m2);

        bool* exportedArray;
        exportedArray = testSet.exportArray();

        CHECK(exportedArray[0] == m1);
        CHECK(exportedArray[1] == m2);

        delete [] exportedArray;
    }
}


TEST_CASE("GenericSet<int> Set", "[GenericSet_lib]") {
    // Used to test GenericSet with objects other than the default data types
    GenericSet<GenericSet<int>> testSet;

    // Building the member sets for the tests
    int v1 = 5, v2 = 12;
    GenericSet<int> m1, m2;
    m1.add(v1);
    m1.add(v2);
    m2.add(v2);
    m2.add(v1);

    // Tests the default constructor to make sure it creates an empty set
    SECTION("Constructor check"){
        CHECK(testSet.getSize() == 0);
        CHECK(!testSet.isMember(m1));
    }

        // Tests the add() and isMember() functions of GenericSet
    SECTION("Adding Members and isMember"){
        CHECK(!testSet.isMember(m1));

        testSet.add(m1);
        CHECK(testSet.isMember(m1));
        CHECK(!testSet.isMember(m2));

        testSet.add(m2);
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 2);
    }

        // Tests the remove() function of GenericSet
    SECTION("Removing Members"){
        testSet.add(m1);
        testSet.add(m2);

        testSet.remove(m1);

        CHECK(!testSet.isMember(m1));
        CHECK(testSet.isMember(m2));
        CHECK(testSet.getSize() == 1);
    }

        // Tests the array export function
    SECTION("Export Array Test"){
        testSet.add(m1);
        testSet.add(m2);

        GenericSet<int>* exportedArray;
        exportedArray = testSet.exportArray();

        CHECK(exportedArray[0] == m1);
        CHECK(exportedArray[1] == m2);

        delete [] exportedArray;
    }
}
