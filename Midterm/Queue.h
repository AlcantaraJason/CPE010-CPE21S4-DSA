#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {
        std::cout << "An empty queue has been created.\n";
    }

    // Check if empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Enqueue
    void enqueue(const T& item) {
        Node* newNode = new Node{ item, nullptr };
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Enqueued: " << item << std::endl;
    }

    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
            rear = nullptr;
    }

    // Get front value
    T getFrontValue() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty.");
        }
        return front->data;
    }

    // Display 
    void display() const {
        if (isEmpty()) {
            std::cout << "[Queue is empty]" << std::endl;
            return;
        }

        Node* temp = front;
        std::cout << "Queue: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "(Front ? Back)" << std::endl;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif 
