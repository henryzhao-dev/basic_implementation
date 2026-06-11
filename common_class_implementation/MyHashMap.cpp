//
// Created by Henry    on 2026/6/6.
//

#include "MyHashMap.h"

#include <stdexcept>
#include <iostream>

MyHashMap::MyHashMap() {
    capacity = 8;
    size = 0;

    buckets = new Entry*[capacity];

    for (int i = 0; i < capacity; ++i) {
        buckets[i] = nullptr;
    }
}

MyHashMap::~MyHashMap() {
    for (int i = 0; i < capacity; ++i) {
        Entry* current = buckets[i];

        while (current != nullptr) {
            Entry* nextEntry = current->next;
            delete current;
            current = nextEntry;
        }
    }
    delete[] buckets;
}


int MyHashMap::hash(int key) {
    return key % capacity;
}

void MyHashMap::put(int key, int value) {
    int index = hash(key);

    Entry* current = buckets[index];

    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    Entry* newEntry = new Entry;
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = buckets[index];

    buckets[index] = newEntry;
    size++;
}

int MyHashMap::get(int key) {
    int index = hash(key);

    Entry* current = buckets[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    throw std::out_of_range("key not found");
}

void MyHashMap::remove(int key) {
    int index = hash(key);

    Entry* current = buckets[index];
    Entry* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }

            delete current;
            size--;
            return;
        }
        prev = current;
        current = current->next;
    }

    throw std::out_of_range("key not found");
}

bool MyHashMap::containsKey(int key) {
    int index = hash(key);

    Entry* current = buckets[index];

    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }

        current = current->next;
    }
    return false;
}

int MyHashMap::getSize() {
    return size;
}

bool MyHashMap::isEmpty() {
    return size == 0;
}

void MyHashMap::print() {
    for (int i = 0; i < capacity; ++i) {
        std::cout << "bucket[" << i << "]: ";

        Entry* current = buckets[i];

        while (current != nullptr) {
            std::cout << "(" << current->key << ", " << current->value << ") -> ";
            current = current->next;
        }

        std::cout << "nullptr" << std::endl;
    }
}







