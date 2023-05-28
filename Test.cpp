#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;
using namespace std;
TEST_SUITE("MagicalContainer Tests") {
    TEST_CASE("Add and Remove Elements") {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(25);
        container.addElement(3);
        container.addElement(17);
        container.addElement(9);

        CHECK(container.size() == 5);

        SUBCASE("Ascending Order") {
            vector<int> expected = {2, 3, 9, 17, 25};
            vector<int> actual = container.getElements();

            CHECK(actual == expected);
        }

        SUBCASE("Cross Order") {
            vector<int> expected = {2, 25, 17, 9, 3};

            MagicalContainer::SideCrossIterator crossIter(container);
            vector<int> actual;
            for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
                actual.push_back(*it);
            }

            CHECK(actual == expected);
        }

        SUBCASE("Prime Numbers") {
            vector<int> expected = {2, 3, 17};

            MagicalContainer::PrimeIterator primeIter(container);
            vector<int> actual;
            for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
                actual.push_back(*it);
            }

            CHECK(actual == expected);
        }

        container.removeElement(25);
        container.removeElement(9);

        CHECK(container.size() == 3);

        SUBCASE("Ascending Order After Removal") {
            vector<int> expected = {2, 3, 17};
            vector<int> actual = container.getElements();

            CHECK(actual == expected);
        }
    }

    TEST_CASE("Empty Container") {
        MagicalContainer container;

        CHECK(container.size() == 0);

        SUBCASE("Ascending Order (Empty)") {
            vector<int> expected = {};
            vector<int> actual = container.getElements();

            CHECK(actual == expected);
        }

        SUBCASE("Cross Order (Empty)") {
            vector<int> expected = {};

            MagicalContainer::SideCrossIterator crossIter(container);
            vector<int> actual;
            for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
                actual.push_back(*it);
            }

            CHECK(actual == expected);
        }

        SUBCASE("Prime Numbers (Empty)") {
            vector<int> expected = {};

            MagicalContainer::PrimeIterator primeIter(container);
            vector<int> actual;
            for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
                actual.push_back(*it);
            }

            CHECK(actual == expected);
        }
    }

    TEST_CASE("Single Element Container") {
        MagicalContainer container;
        container.addElement(42);

        CHECK(container.size() == 1);

        SUBCASE("Ascending Order (Single Element)") {
            vector<int> expected = {42};
            vector<int> actual = container.getElements();

            CHECK(actual == expected);
        }

        SUBCASE("Cross Order (Single Element)") {
            vector<int> expected = {42};

            MagicalContainer::SideCrossIterator crossIter(container);
            vector<int> actual;
            for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
                actual.push_back(*it);
            }

            CHECK(actual == expected);
        }

        SUBCASE("Prime Numbers (Single Element)") {
            vector<int> expected = {42};

            MagicalContainer::PrimeIterator primeIter(container);
            vector<int> actual;
            for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
                actual.push_back(*it);
            }

            CHECK(actual == expected);
        }

        container.removeElement(42);

        CHECK(container.size() == 0);
    }
}
