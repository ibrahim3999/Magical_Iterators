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
    MagicalContainer& container;
    vector<int> sortedElements;

public:
    AscendingIterator(MagicalContainer& container);

    class Iterator{
        private:
            vector<int>::iterator iter;

        public:
            Iterator(vector<int>::iterator iter):iter(iter){}
            int operator*();
            Iterator& operator++();
            bool operator==(const Iterator& other)const;
            bool operator!=(const Iterator& other)const;

    };

    Iterator begin() ;

    Iterator end() ;
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
