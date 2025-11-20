#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> q;
    std::string students[] = {"Spderman", "Batman", "Hulk", "Superman"};

    // Insert students
    for (auto& name : students) {
        std::cout << "Enqueue: " << name << std::endl;
        q.push(name);
    }

    // Display 
    std::cout << "Queue after enqueues: ";
    std::queue<std::string> temp = q;  
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << "\n";

    // Dequeue the students one by one
    while (!q.empty()) {
        std::cout << "Dequeue: " << q.front() << std::endl;
        q.pop();
    }

    return 0;
}
