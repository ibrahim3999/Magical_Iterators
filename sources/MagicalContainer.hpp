#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
using namespace std;

namespace ariel {

    class MagicalContainer {
        private:
            vector<int> elements;

        public:
            void addElement(int element);
            void removeElement(int element);
            int size() const;
            vector<int> getElements(); 

            class AscendingIterator {
                private:
                    MagicalContainer& container;
                    vector<int> sortedElements;

                public:
                    AscendingIterator(MagicalContainer& container);

                    class Iterator {
                        private:
                            vector<int>::iterator iter;

                        public:
                            Iterator(vector<int>::iterator iter) : iter(iter) {}
                            int operator*();
                            Iterator& operator++();
                            bool operator==(const Iterator& other) const;
                            bool operator!=(const Iterator& other) const;
                    };

                    Iterator begin();
                    Iterator end();
            };

            class SideCrossIterator {
                private:
                    const MagicalContainer& container;
                    vector<int> crossOrderElements;

                public:
                    SideCrossIterator(MagicalContainer& container);

                    class Iterator {
                        private:
                            vector<int>::iterator iter;

                        public:
                            Iterator(vector<int>::iterator iter) : iter(iter) {}
                            int operator*();
                            Iterator& operator++();
                            bool operator==(const Iterator& other) const;
                            bool operator!=(const Iterator& other) const;
                    };

                    Iterator begin();
                    Iterator end();
            };

            class PrimeIterator {
                private:
                    MagicalContainer& container;
                    vector<int> primeElements;

                public:
                    PrimeIterator(MagicalContainer& container);
                    void sortPrimes();
                    bool isPrime(int number) const;
                    
                    class Iterator {
                        private:
                            vector<int>::iterator iter;

                        public:
                            Iterator(vector<int>::iterator iter) : iter(iter) {}
                            int operator*();
                            Iterator& operator++();
                            bool operator==(const Iterator& other) const;
                            bool operator!=(const Iterator& other) const;
                    };

                    Iterator begin();
                    Iterator end();
            };

    };

} // namespace ariel

#endif  // MAGICAL_CONTAINER_HPP
