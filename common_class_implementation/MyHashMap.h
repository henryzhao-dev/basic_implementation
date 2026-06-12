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
    void resize();
    void clearBucket();

public:
    MyHashMap();
    ~MyHashMap();

    MyHashMap(const MyHashMap& other);
    MyHashMap& operator=(const MyHashMap& other);

    void put(int key, int value);
    int get(int key);
    void remove(int key);
    bool containsKey(int key);
    int getSize();
    bool isEmpty();
    void print();


};


#endif //CPP_SYSTEM_LAB_MYHASHMAP_H