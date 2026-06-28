//
// Created by Henry    on 2026/6/25.
//

#include "MySDS.h"

#include <cstring>

MySDS::MySDS() {
    length = 0;
    capacity = 16;
    data = new char[capacity];
    data[0] = '\0';
}

MySDS::MySDS(const char *str) {
    length = strlen(str);
    capacity = length + 1;

    if (capacity < 16) {
        capacity = 16;
    }

    data = new char[capacity];

    for (int i = 0; i < length; i++) {
        data[i] = str[i];
    }

    data[length] = '\0';
}

MySDS::~MySDS() {
    delete[] data;
}

int MySDS::strlen(const char *str) {
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    return len;
}

int MySDS::size() {
    return length;
}

const char *MySDS::c_str() {
    return data;
}

void MySDS::append(const char *str) {
    int appendLength = strlen(str);
    int newLength = length + appendLength;

    if (newLength + 1 > capacity) {
        int newCapacity = capacity * 2;

        while (newCapacity < newLength) {
            newCapacity *= 2;
        }

        resize(newCapacity);
    }

    for (int i = 0; i < appendLength; i++) {
        data[length + i] = str[i];
    }

    length = newLength;
    data[length] = '\0';
}

void MySDS::resize(int newCapacity) {
    char* newData = new char[newCapacity];

    for (int i = 0; i <= length; i++) {
        newData[i] = data[i];
    }

    delete[] data;

    data = newData;
    capacity = newCapacity;
}






