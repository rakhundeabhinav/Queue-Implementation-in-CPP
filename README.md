
## 📦 Queue in C++

### 🎯 Aim  
To study and implement Queue operations in C++ using object-oriented principles, including insertion (`enqueue`), deletion (`dequeue`), and traversal. This experiment also explores how queues differ from stacks and arrays in terms of memory allocation, order of processing, and operational efficiency.

---

### 📚 Theory  
A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. The first element inserted is the first to be removed—similar to a queue at a ticket counter.

In a class-based implementation, we use two pointers:
- `front` → points to the first element in the queue.
- `rear` → points to the last element in the queue.

---

### 🔑 Characteristics of Queues  
- **FIFO Order**: First element inserted is the first to be removed.  
- **Linear Structure**: Elements are arranged sequentially.  
- **Restricted Access**: Insertion at rear, deletion at front.  
- **Overflow/Underflow**:  
  - Overflow occurs when the queue is full.  
  - Underflow occurs when the queue is empty.

---

### 🔄 Types of Queues  
- **Simple (Linear) Queue** → Basic FIFO structure.  
- **Circular Queue** → Reuses empty spaces by connecting rear to front.  
- **Double-Ended Queue (Deque)** → Insertion and deletion allowed at both ends.  
- **Priority Queue** → Elements dequeued based on priority, not order.

---

### 📋 Algorithm (Class-Based Queue)

**Start**

1. Define a class `Queue` with:
   - Dynamic array `arr`
   - Integer variables `front`, `rear`, and `capacity`

2. **Constructor**:
   - Initialize `front = rear = -1`
   - Allocate memory for `arr` of size `capacity`

3. **enqueue(int value)**:
   - If queue is full → throw `overflow_error`
   - If queue is empty → set `front = rear = 0`
   - Else → update `rear = (rear + 1) % capacity`
   - Insert `value` at `arr[rear]`

4. **dequeue()**:
   - If queue is empty → throw `underflow_error`
   - Store `arr[front]` in `value`
   - If `front == rear` → reset both to `-1`
   - Else → update `front = (front + 1) % capacity`
   - Return `value`

5. **peek()**:
   - If queue is empty → throw `underflow_error`
   - Return `arr[front]`

6. **isEmpty()**:
   - Return `true` if `front == -1`

7. **isFull()**:
   - Return `true` if `(rear + 1) % capacity == front`

8. **display()**:
   - If queue is empty → print "Queue is empty"
   - Else → traverse from `front` to `rear` using modulo arithmetic

9. **Destructor**:
   - Deallocate memory for `arr`

**End**

---

### 🚀 Applications of Queues  
- CPU scheduling (Round Robin, FCFS)  
- Disk scheduling  
- Data buffering (IO Buffers, Print Queue, Keyboard Buffer)  
- Breadth-First Search (BFS) in graphs  
- Order processing systems (ticket booking, call centers)  
- Resource management in operating systems

---

### 🧠 Conclusion  
Queues are essential for managing data in FIFO order.  
They provide efficient handling of sequential processes like scheduling and buffering.  
This experiment demonstrated:
- `enqueue()` → insertion at rear  
- `dequeue()` → deletion from front  
- Utility functions → `peek()`, `isEmpty()`, `isFull()`, `display()`  

This forms the foundation for advanced queue structures such as circular queues, deques, and priority queues.  
Mastering queues is crucial for solving real-world scheduling, resource allocation, and graph traversal problems.
