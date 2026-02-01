// LeetCode Problem 641: Design Circular Deque

#include <iostream>
using namespace std;

class MyCircularDeque {
private:
    int* arr;
    int capacity;
    int size;
    int frontIdx;
    int rearIdx;

public:
    // Constructor
    MyCircularDeque(int k) {
        capacity = k;
        arr = new int[k];
        size = 0;
        frontIdx = 0;
        rearIdx = 0;
    }

    // Destructor
    ~MyCircularDeque() {
        delete[] arr;
    }

    // Insert at front
    bool insertFront(int value) {
        if (isFull()) return false;
        frontIdx = (frontIdx - 1 + capacity) % capacity;
        arr[frontIdx] = value;
        size++;
        return true;
    }

    // Insert at rear
    bool insertLast(int value) {
        if (isFull()) return false;
        arr[rearIdx] = value;
        rearIdx = (rearIdx + 1) % capacity;
        size++;
        return true;
    }

    // Delete from front
    bool deleteFront() {
        if (isEmpty()) return false;
        frontIdx = (frontIdx + 1) % capacity;
        size--;
        return true;
    }

    // Delete from rear
    bool deleteLast() {
        if (isEmpty()) return false;
        rearIdx = (rearIdx - 1 + capacity) % capacity;
        size--;
        return true;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) return -1;
        return arr[frontIdx];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) return -1;
        return arr[(rearIdx - 1 + capacity) % capacity];
    }

    // Check if deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if deque is full
    bool isFull() {
        return size == capacity;
    }

    // Display deque elements (for testing)
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[(frontIdx + i) % capacity] << " ";
        }
        cout << endl;
    }
};

// Main function to test
int main() {
    int n;
    cout << "Enter capacity of deque: ";
    cin >> n;
    MyCircularDeque deque(n);
    cout << "Insert elements at rear: ";
    for (int i = 1; i <= n; i++) {
        deque.insertLast(i);
    }
    cout << "Current deque: ";
    deque.display();
    cout << "Front element: " << deque.getFront() << endl;
    cout << "Rear element: " << deque.getRear() << endl;
    cout << "Insert 0 at front: " << (deque.insertFront(0) ? "Success" : "Failed (Full)") << endl;
    deque.display();
    cout << "Delete front: " << (deque.deleteFront() ? "Success" : "Failed (Empty)") << endl;
    cout << "Delete rear: " << (deque.deleteLast() ? "Success" : "Failed (Empty)") << endl;
    cout << "Deque after deletions: ";
    deque.display();
    cout << "New front: " << deque.getFront() << ", New rear: " << deque.getRear() << endl;
    return 0;
}

