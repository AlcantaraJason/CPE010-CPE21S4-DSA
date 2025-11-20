#include <iostream>
#include <queue>

int main() {
    std::queue<int> x;  
    int a, b;

    x.push(5);
    x.push(3);
    x.push(2);
    x.pop(); 

    x.push(7);

    if (!x.empty()) {
        a = x.front();
        x.pop();
        std::cout << "Dequeued a = " << a << std::endl;
    }

    if (!x.empty()) {
        b = x.front();
        x.pop();
        std::cout << "Dequeued b = " << b << std::endl;
    }

    // Display remaining queue
    std::cout << "Final queue: ";
    std::queue<int> temp = x;
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << "(Front ? Back)" << std::endl;

    return 0;
}

