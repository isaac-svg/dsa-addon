const { LinkedList, VectorList, Queue, Stack } = require('dsa-native');

// Linked list example
const linkedList = new LinkedList();
linkedList.addHead(42);
linkedList.addTail("hello");
console.log(linkedList.size()); // Output: 2

// Queue example
const queue = new Queue();
queue.enqueue(10);
queue.enqueue(20);
console.log(queue.dequeue()); // Output: 10

// ... (similar usage for VectorList and Stack)
