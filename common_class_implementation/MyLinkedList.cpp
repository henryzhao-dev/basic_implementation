//
// Created by Henry    on 2026/5/31.
//

#include "MyLinkedList.h"
#include <iostream>
#include <stdexcept>


MyLinkedList::MyLinkedList() {
    head = nullptr;
    length = 0;
}

MyLinkedList::~MyLinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;

        delete current;

        current = nextNode;
    }
}


void MyLinkedList::addFirst(int value) {
    Node* newNode = new Node(value);

    newNode->next = head;

    head = newNode;

    length++;
}

void MyLinkedList::print() {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current-> value << " ";

        current = current-> next;
    }

    std::cout << std::endl;
}

void MyLinkedList::addLast(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        length++;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    length++;
}

int MyLinkedList::get(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("index out of range");
    }

    Node* current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

void MyLinkedList::remove(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("index out of range");
    }

    if (index == 0) {
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        length--;
        return;
    }

    Node* prev = head;
    for (int i = 0; i < index - 1; ++i) {
        prev = prev->next;
    }

    Node* target = prev->next;
    prev->next = target->next;

    delete prev;
    length--;
}

int MyLinkedList::size() {
    return length;
}






