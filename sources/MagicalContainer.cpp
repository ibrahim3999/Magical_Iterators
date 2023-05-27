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
//--------------------- SideCrossIterator ------------------------------------

SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container(container) {
    crossOrderElements = container.getElements();
    std::sort(crossOrderElements.begin(), crossOrderElements.end(), [](int a, int b) {
        if (a % 2 == 0 && b % 2 == 0) {
            return a < b;
        } else if (a % 2 != 0 && b % 2 != 0) {
            return a > b;
        } else {
            return a % 2 == 0;
        }
    });
}

SideCrossIterator::Iterator SideCrossIterator::begin()  {
    return Iterator(crossOrderElements.begin());
}

SideCrossIterator::Iterator SideCrossIterator::end()  {
    return Iterator(crossOrderElements.end());
}

// SideCrossIterator::Iterator implementation

int SideCrossIterator::Iterator::operator*() {
    return *iter;
}

SideCrossIterator::Iterator& SideCrossIterator::Iterator::operator++() {
    ++iter;
    return *this;
}

bool SideCrossIterator::Iterator::operator==(const Iterator& other) const {
    return iter == other.iter;
}

bool SideCrossIterator::Iterator::operator!=(const Iterator& other) const {
    return iter != other.iter;
}
PrimeIterator::PrimeIterator( MagicalContainer& container) : container(container) {
    const std::vector<int>& elements = container.getElements();
    for (int num : elements) {
        if (isPrime(num)) {
            primeElements.push_back(num);
        }
    }
}

bool PrimeIterator::isPrime(int number) const {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

PrimeIterator::Iterator PrimeIterator::begin()  {
    return Iterator(primeElements.begin());
}

PrimeIterator::Iterator PrimeIterator::end()  {
    return Iterator(primeElements.end());
}

// PrimeIterator::Iterator implementation

int PrimeIterator::Iterator::operator*() {
    return *iter;
}

PrimeIterator::Iterator& PrimeIterator::Iterator::operator++() {
    ++iter;
    return *this;
}

bool PrimeIterator::Iterator::operator==(const Iterator& other) const {
    return iter == other.iter;
}

bool PrimeIterator::Iterator::operator!=(const Iterator& other) const {
    return iter != other.iter;
}

