#include "MagicalContainer.hpp"
#include <algorithm>
namespace ariel{
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

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container) {
        sortedElements = container.getElements();
        std::sort(sortedElements.begin(), sortedElements.end());
    }

    MagicalContainer::AscendingIterator::Iterator MagicalContainer::AscendingIterator::begin() {
        return Iterator(sortedElements.begin());
    }

    MagicalContainer::AscendingIterator::Iterator MagicalContainer::AscendingIterator::end() {
        return Iterator(sortedElements.end());
    }

    // AscendingIterator::Iterator implementation

    int MagicalContainer::AscendingIterator::Iterator::operator*() {
        return *iter;
    }

    MagicalContainer::AscendingIterator::Iterator& MagicalContainer::AscendingIterator::Iterator::operator++() {
        ++iter;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::Iterator::operator==(const Iterator& other) const {
        return iter == other.iter;
    }

    bool MagicalContainer::AscendingIterator::Iterator::operator!=(const Iterator& other) const {
        return iter != other.iter;
    }
    //--------------------- SideCrossIterator ------------------------------------

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container(container) {
        crossOrderElements = container.getElements();
      std::sort(crossOrderElements.begin(), crossOrderElements.end(), [](int a, int b) {
        if (a % 2 == 0 && b % 2 == 0) {
            return a < b;  // Sort even numbers in ascending order
        } else if (a % 2 != 0 && b % 2 != 0) {
            return a > b;  // Sort odd numbers in descending order
        } else if (a % 2 == 0 && b % 2 != 0) {
            return true;   // Even numbers come before odd numbers
        } else {
            return false;  // Odd numbers come after even numbers
        }
    });

    }

    MagicalContainer::SideCrossIterator::Iterator MagicalContainer::SideCrossIterator::begin()  {
        return Iterator(crossOrderElements.begin());
    }

    MagicalContainer::SideCrossIterator::Iterator MagicalContainer::SideCrossIterator::end()  {
        return Iterator(crossOrderElements.end());
    }

    // SideCrossIterator::Iterator implementation

    int MagicalContainer::SideCrossIterator::Iterator::operator*() {
        return *iter;
    }

    MagicalContainer::SideCrossIterator::Iterator& MagicalContainer::SideCrossIterator::Iterator::operator++() {
        ++iter;
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::Iterator::operator==(const Iterator& other) const {
        return iter == other.iter;
    }

    bool MagicalContainer::SideCrossIterator::Iterator::operator!=(const Iterator& other) const {
        return iter != other.iter;
    }
    MagicalContainer::PrimeIterator::PrimeIterator( MagicalContainer& container) : container(container) {
        const std::vector<int>& elements = container.getElements();
        for (int num : elements) {
            if (isPrime(num)) {
                primeElements.push_back(num);
            }
        }
    }

    bool MagicalContainer::PrimeIterator::isPrime(int number) const {
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

    void MagicalContainer::PrimeIterator::sortPrimes() {
        std::sort(primeElements.begin(), primeElements.end());
    }


    MagicalContainer::PrimeIterator::Iterator MagicalContainer::PrimeIterator::begin()  {
        MagicalContainer::PrimeIterator::sortPrimes();
        return Iterator(primeElements.begin());
    }

    MagicalContainer::PrimeIterator::Iterator MagicalContainer::PrimeIterator::end()  {
        return Iterator(primeElements.end());
    }

    // PrimeIterator::Iterator implementation

    int MagicalContainer::PrimeIterator::Iterator::operator*() {
        return *iter;
    }

    MagicalContainer::PrimeIterator::Iterator& MagicalContainer::PrimeIterator::Iterator::operator++() {
        ++iter;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::Iterator::operator==(const Iterator& other) const {
        return iter == other.iter;
    }

    bool MagicalContainer::PrimeIterator::Iterator::operator!=(const Iterator& other) const {
        return iter != other.iter;
    }

}