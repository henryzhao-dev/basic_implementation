//
// Created by Henry    on 2026/6/13.
//

#include "MyStack.h"

#include <stdexcept>

void MyStack::push(int value) {
    list.add(value);
}

int MyStack::pop() {
    if (list.size() == 0) {
        throw std::out_of_range("stack is empty");
    }

    int lastIndex = list.size() - 1;
    int value = list.get(lastIndex);
    list.remove(lastIndex);

    return value;
}

int MyStack::peek() {
    if (list.size() == 0) {
        throw std::out_of_range("stack is empty");
    }

    return list.get(list.size() - 1);
}

bool MyStack::isEmpty() {
    return size() == 0;
}

int MyStack::size() {
    return list.size();
}




