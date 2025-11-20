#include <iostream>
#include <string>
#include "Queue.h"


int main() {
    Queue<std::string> CPE2154;

    CPE2154.enqueue("Spiderman");
    CPE2154.enqueue("Batman");
    CPE2154.enqueue("Hulk");
    CPE2154.enqueue("Thanos");
    CPE2154.enqueue("Naruto");
    CPE2154.enqueue("Hikaru");

    CPE2154.getRear();
    CPE2154.getFront();

    CPE2154.dequeue();
    CPE2154.getFront();

    CPE2154.display();

    return 0;
}
