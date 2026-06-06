//
// Created by Henry    on 2026/5/31.
//

#ifndef CPP_SYSTEM_LAB_MYLINKEDLIST_H
#define CPP_SYSTEM_LAB_MYLINKEDLIST_H


class MyLinkedList {

private:
    struct Node {
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            this->next = nullptr;
        }
    };

    Node* head;
    int length;

public:

    MyLinkedList();
    ~MyLinkedList();

    void addFirst(int value);
    void print();
    void addLast(int value);
    int get(int index);
    void remove(int index);
    int size();

};


#endif //CPP_SYSTEM_LAB_MYLINKEDLIST_H