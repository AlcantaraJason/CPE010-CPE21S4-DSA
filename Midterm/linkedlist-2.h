#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
Node<T>* new_node(T data) {
    Node<T>* newNode = new Node<T>();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
bool linearS(Node<T>* head, T value) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;  // The Value is found
        }
        temp = temp->next;
    }
    return false;  // the Value not found
}

#endif
