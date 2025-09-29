//Abhinav Rakhunde
//PRN:24070123001

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }
    ~Queue() {
        delete[] arr;
    }
    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (rear + 1) % capacity == front;
    }
    void enqueue(int value) {
        if (isFull())
            throw overflow_error("Queue Overflow");

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % capacity;

        arr[rear] = value;
    }
    int dequeue() {
        if (isEmpty())
            throw underflow_error("Queue Underflow");

        int value = arr[front];
        if (front == rear) // Only one element
            front = rear = -1;
        else
            front = (front + 1) % capacity;

        return value;
    }
    int peek() const {
        if (isEmpty())
            throw underflow_error("Queue is empty");
        return arr[front];
    }
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    try {
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.display();

        cout << "Dequeued: " << q.dequeue() << endl;
        q.display();

        cout << "Front: " << q.peek() << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

/* OUTPUT:
Queue: 10 20 30 
Dequeued: 10
Queue: 20 30 
Front: 20
  */
