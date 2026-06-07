//
// Created by Henry    on 2026/6/6.
//

#ifndef CPP_SYSTEM_LAB_MYHASHMAP_H
#define CPP_SYSTEM_LAB_MYHASHMAP_H


class MyHashMap {

private:
    struct Entry {
        int key;
        int value;
        Entry* next;
    };

    Entry** buckets;
    int capacity;
    int size;
    int hash(int key);

public:
    MyHashMap();
    ~MyHashMap();

    void put(int key, int value);
    int get(int key);


};


#endif //CPP_SYSTEM_LAB_MYHASHMAP_H