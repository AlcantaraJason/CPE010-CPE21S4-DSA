#include <iostream>
#include <thread>

int globalVar = 0;

void add(int value) {
    globalVar += value;
}

int main() {
    std::thread t1(add, 10);
    std::thread t2(add, 20);
    std::thread t3(add, 30);

    std::cout << "Before any join, globalVar = " << globalVar << std::endl;

    t1.join();
    std::cout << "After t1.join(), globalVar = " << globalVar << std::endl;

    t2.join();
    std::cout << "After t2.join(), globalVar = " << globalVar << std::endl;

    t3.join();
    std::cout << "After t3.join(), globalVar = " << globalVar << std::endl;

    return 0;
}
