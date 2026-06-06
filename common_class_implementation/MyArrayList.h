//
// Created by Henry    on 2026/5/30.
//

#ifndef CPP_SYSTEM_LAB_MYARRAYLIST_H
#define CPP_SYSTEM_LAB_MYARRAYLIST_H


class MyArrayList {
private:
    int* data;
    int capacity;
    int length;

    void resize();

public:
    MyArrayList();
    ~MyArrayList();

    MyArrayList(const MyArrayList& other);
    MyArrayList& operator=(const MyArrayList& other);

    void add(int value);
    int get(int index);
    int size();
    void set(int index, int value);
    void remove(int index);
    void insert(int index, int value);
    bool isEmpty();
    void clear();
    int getCapacity();
};


#endif //CPP_SYSTEM_LAB_MYARRAYLIST_H