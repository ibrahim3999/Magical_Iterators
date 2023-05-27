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

// AscendingIterator

AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container) {
    sortedElements = container.getElements();
    std::sort(sortedElements.begin(), sortedElements.end());
}

AscendingIterator::Iterator AscendingIterator::begin() {
    return Iterator(sortedElements.begin());
}

AscendingIterator::Iterator AscendingIterator::end() {
    return Iterator(sortedElements.end());
}

// AscendingIterator::Iterator implementation

int AscendingIterator::Iterator::operator*() {
    return *iter;
}

AscendingIterator::Iterator& AscendingIterator::Iterator::operator++() {
    ++iter;
    return *this;
}

bool AscendingIterator::Iterator::operator==(const Iterator& other) const {
    return iter == other.iter;
}

bool AscendingIterator::Iterator::operator!=(const Iterator& other) const {
    return iter != other.iter;
}

