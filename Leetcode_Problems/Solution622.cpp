// Leetcode Problem 622: Design Circular Queue
#include <iostream>
using namespace std;

// class in which circular queue algorithm perform
class MyCircularQueue {
private:
    int* arr;
    int capacity;
    int frontIdx, rearIdx;
    int size;

public:
    MyCircularQueue(int k) {
        capacity = k;
        arr = new int[k];
        frontIdx = 0;
        rearIdx = 0;
        size = 0;
    }

    // Garbage Collection && Destructor
    ~MyCircularQueue() {
        delete[] arr;
    }

    // Enqueue Operation
    bool enQueue(int value) {
        if (isFull()) return false;
        arr[rearIdx] = value;
        rearIdx = (rearIdx + 1) % capacity;
        size++;
        return true;
    }

    // Dequeue Operation
    int deQueue() {
        if (isEmpty()) return -1;
        int val = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        size--;
        return val;
    }

    // Peek Operation
    int Front() {
        if (isEmpty()) return -1;
        return arr[frontIdx];
    }

    // Last Element Value Operation
    int Rear() {
        if (isEmpty()) return -1;
        return arr[(rearIdx - 1 + capacity) % capacity];
    }

    // Check queue is empty or not
    bool isEmpty() {
        return size == 0;
    }

    // Check queue is full or not
    bool isFull() {
        return size == capacity;
    }

    // Display the queue data
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[(frontIdx + i) % capacity] << " ";
        }
        cout << "\n";
    }
};

// Main function
int main() {
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;
    MyCircularQueue queue(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        queue.enQueue(value);
    }
    cout << "Queue data: ";
    queue.display();
    cout << "Front element: " << queue.Front() << endl;
    cout << "Rear element: " << queue.Rear() << endl;
    cout << "Dequeued element: " << queue.deQueue() << endl;
    cout << "Queue after dequeue: ";
    queue.display();
    cout << "New front element: " << queue.Front() << endl;
    cout << "New rear element: " << queue.Rear() << endl;
    return 0;
}
