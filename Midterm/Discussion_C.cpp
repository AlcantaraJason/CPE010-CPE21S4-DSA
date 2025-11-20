#include <iostream>
#include "QUEUE_H.h"

int main() {
    Queue<int> x; // CreateQueue()

    x.enqueue(5);
    x.enqueue(3);
    x.enqueue(2);

    x.dequeue(); // Removes 5

    x.enqueue(7);

    // Dequeue the variable a
    if (!x.isEmpty()) {
        int a = x.getFrontValue();
        x.dequeue();
        std::cout << "Dequeued a: " << a << std::endl;
    }

    // Dequeue the variable b
    if (!x.isEmpty()) {
        int b = x.getFrontValue();
        x.dequeue();
        std::cout << "Dequeued b: " << b << std::endl;
    }

    x.display();

    return 0;
}
