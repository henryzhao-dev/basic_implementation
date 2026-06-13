//
// Created by Henry    on 2026/6/13.
//

#ifndef CPP_SYSTEM_LAB_MYSTACK_H
#define CPP_SYSTEM_LAB_MYSTACK_H

#include "MyArrayList.h"

class MyStack {
private:
    MyArrayList list;

public:
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};


#endif //CPP_SYSTEM_LAB_MYSTACK_H