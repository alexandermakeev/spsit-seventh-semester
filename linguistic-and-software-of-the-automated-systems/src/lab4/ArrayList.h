#ifndef UNTITLED_ARRAYLIST_H
#define UNTITLED_ARRAYLIST_H


#include <cstddef>
#include <menu.h>
#include <type_traits>

template <class Item>
class ArrayList {
    Item *a;
    std::size_t count = 0;
    std::size_t aSize;
    void resize(std::size_t newSize);
public:
    ArrayList(std::size_t  size) {
        this->aSize = size;
        a = new Item[size];
    }
    ArrayList() {
        this->aSize = 10;
        a = new Item[aSize];
    }
    ~ArrayList() {
//        delete [] a;
    }
    std::size_t size();
    void add(Item item);
    Item get(int index);
    Item first();
    Item last();
};

template<class Item>
std::size_t ArrayList<Item>::size() {
    return count;
}

template<class Item>
void ArrayList<Item>::resize(std::size_t newSize) {
    Item *temp = new Item[newSize];
    for (int i = 0; i < count; ++i) {
        temp[i] = a[i];
    }
    delete [] a;
    a = temp;
}

template<class Item>
void ArrayList<Item>::add(Item item) {
    if (count == aSize) {
        aSize = count * 2;
        resize(aSize);
    }
    a[count++] = item;
}

template<class Item>
Item ArrayList<Item>::get(int index) {
    if (index < 0 || index > count) throw "Out of range";
    return a[index];
}

template<class Item>
Item ArrayList<Item>::first() {
    if (count == 0) throw "Out of range";
    return a[0];
}

template<class Item>
Item ArrayList<Item>::last() {
    if (count == 0) throw "Out of range";
    return a[count-1];
}


#endif //UNTITLED_ARRAYLIST_H
