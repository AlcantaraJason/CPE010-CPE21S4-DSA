#include <iostream>
#define MAX 10 
 
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

//Class Linked Lists
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    Node* reverseList() const {
        Node* reversed = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* newNode = new Node(curr->data);
            newNode->next = reversed;
            reversed = newNode;
            curr = curr->next;
        }
        return reversed;
    }

    bool isPalindrome() {
        Node* reversedHead = reverseList();
        Node* p1 = head;
        Node* p2 = reversedHead;

        bool result = true;
        while (p1 != NULL && p2 != NULL) {
            if (p1->data != p2->data) {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        while (reversedHead != NULL) {
            Node* temp = reversedHead;
            reversedHead = reversedHead->next;
            delete temp;
        }

        return result;
    }
};

//Function Helper to Create List from Integers
LinkedList buildListFromNumber(int num) {
    LinkedList list;
    if (num == 0) {
        list.insertAtEnd(0);
        return list;
    }

    int digits[10]; 
    int count = 0;
    while (num > 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

    for (int i = count - 1; i >= 0; --i) {
        list.insertAtEnd(digits[i]);
    }

    return list;
}

int main() {
    int testCases[] = {10201, 1003003001, 88, 0, 202};
    int count = sizeof(testCases) / sizeof(testCases[0]);

    std::cout << "Palindromic Number Check (Linked List Only)\n";
    std::cout << "-------------------------------------------\n";

    for (int i = 0; i < count; ++i) {
        int num = testCases[i];
        LinkedList list = buildListFromNumber(num);
        std::cout << "Number " << num << " is "
                  << (list.isPalindrome() ? "" : "not ") << "a palindrome.\n";
    }

    return 0;
}
