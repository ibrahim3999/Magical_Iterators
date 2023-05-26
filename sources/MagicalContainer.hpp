#ifndef MAGICAL_CONTAINER_H
#define MAGICAL_CONTAINER_H

#include <vector>

class MagicalContainer {
public:
    void addElement(int element);
    void removeElement(int element);
    int size() const;

private:
    std::vector<int> elements;
};

#endif
