#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

TEST_CASE("Testing MagicalContainer") {
    SUBCASE("Adding and removing elements") {
        MagicalContainer container;
        CHECK(container.size() == 0);
        
        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        
        CHECK(container.size() == 3);
        
        container.removeElement(20);
        
        CHECK(container.size() == 2);

        container.removeElement(10);

        CHECK(container.size() == 1);
    }
    
    SUBCASE("Adding and removing elements - edge case") {
        MagicalContainer container;
        
        container.addElement(42);
        container.removeElement(42);
        
        CHECK(container.size() == 0);
    }
}
