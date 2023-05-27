#include "MagicalContainer.hpp"
#include <algorithm>

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}

vector<int> MagicalContainer::getElements()  {
    return elements;
}
