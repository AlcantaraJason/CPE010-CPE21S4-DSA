#include <iostream>
#define SIZE 100

using namespace std;

class Queue {
private:
    int items[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "The Queue is Overflow" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        items[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "The Queue is Underflow" << endl;
            return;
        }
        cout << "Dequeued: " << items[front] << endl;
        front++;
    }

    // Display the queue
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); 

    return 0;
}
