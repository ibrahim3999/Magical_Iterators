#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
using namespace std;

class MagicalContainer {
private:
    vector<int> elements;

public:
    void addElement(int element);
    void removeElement(int element);
    int size() const;
    vector<int> getElements();  // Updated declaration
};

class AscendingIterator {
private:
    const MagicalContainer& container;
    vector<int> sortedElements;

public:
    AscendingIterator(const MagicalContainer& container);

    class Iterator;

    Iterator begin() const;

    Iterator end() const;
};

class SideCrossIterator {
private:
    const MagicalContainer& container;
    vector<int> crossOrderElements;

public:
    SideCrossIterator(const MagicalContainer& container);

    class Iterator;

    Iterator begin() const;

    Iterator end() const;
};

class PrimeIterator {
private:
    const MagicalContainer& container;
    vector<int> primeElements;

public:
    PrimeIterator(const MagicalContainer& container);

    bool isPrime(int number) const;

    class Iterator;

    Iterator begin() const;

    Iterator end() const;
};

#endif  // MAGICAL_CONTAINER_HPP
