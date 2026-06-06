//
// Created by Henry    on 2026/5/30.
//

#include "MyArrayList.h"

#include <stdexcept>

MyArrayList::MyArrayList() {
    capacity = 2;
    length = 0;
    data = new int[capacity];
}

MyArrayList::~MyArrayList() {
    delete[] data;
}

MyArrayList::MyArrayList(const MyArrayList &other) {
    capacity = other.capacity;
    length = other.length;
    data = new int[capacity];

    for (int i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
}

MyArrayList& MyArrayList::operator=(const MyArrayList &other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;

    capacity = other.capacity;
    length = other.length;
    data = new int[capacity];

    for (int i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }

    return *this;
}



void MyArrayList::add(int value) {
    if (length == capacity) {
        resize();
    }

    data[length] = value;
    length++;
}

int MyArrayList::get(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("index out of range");
    }

    return data[index];
}

int MyArrayList::size() {
    return length;
}

void MyArrayList::resize() {
    int newCapacity = capacity * 2;
    int* newData = new int[newCapacity];

    for (int i  = 0; i < length; i++) {
        newData[i] = data[i];
    }

    delete[] data;

    data = newData;
    capacity = newCapacity;
}

void MyArrayList::set(int index, int value) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("index out of range");
    }

    data[index] = value;
}

void MyArrayList::remove(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("index out of range");
    }

    for (int i = index; i < length; i++) {
        data[i] = data[i + 1];
    }

    length--;
}

void MyArrayList::insert(int index, int value) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("index out of range");
    }

    if (length == capacity) {
        resize();
    }

    for (int i = length; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = value;
    length++;
}

bool MyArrayList::isEmpty() {
    return length == 0;
}

void MyArrayList::clear() {
    length = 0;
}

int MyArrayList::getCapacity() {
    return capacity;
}











