#include <iostream>
#include <vector>
using namespace std;

// Task 1: Sum of a List of Numbers

// Recursive version
int sumRecursive(const vector<int>& nums, int n) {
    if (n == 0) return 0;
    return nums[n - 1] + sumRecursive(nums, n - 1);
}

// Iterative version
int sumIterative(const vector<int>& nums) {
    int total = 0;
    for (int num : nums) {
        total += num;
    }
    return total;
}

// Task 2: Fibonacci

// Recursive version
int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative version
int fibonacciIterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Main
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Sum Recursive: " << sumRecursive(nums, nums.size()) << endl;
    cout << "Sum Iterative: " << sumIterative(nums) << endl;

    int n = 10;
    cout << "Fibonacci Recursive (" << n << "): " << fibonacciRecursive(n) << endl;
    cout << "Fibonacci Iterative (" << n << "): " << fibonacciIterative(n) << endl;

    return 0;
}