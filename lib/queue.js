const {Queue: Queuenative} = require('../build/Release/dsa-native');



/**
 * 
 */
class Queue {
  constructor(iterable = null) {
    this.items = new Queuenative(iterable);
  }
  
  /**
   * Add element to the back of the queue.
   * Runtime: O(1)
   * @param {any} item
   * @returns {queue} instance to allow chaining.
   */
  enqueue(item) {
    this.items.enqueue(item);
    return this;
  }
  
  /**
   * Remove element from the front of the queue.
   * Runtime: O(1)
   * @returns {any} removed value.
   */
  dequeue() {
    return this.items.dequeue();
  }

  
  /**
   * Size of the queue
   * Runtime: O(1)
   */
  get size() {
    return this.items.size;
  }

  /**
   * Return true if is empty false otherwise true
   */
  isEmpty() {
    return !!this.items.size();
  }

  /**
   * Return the most recent value or null if empty.
   * Return O(1)
   */
  peek() {
    if (this.items.isEmpty()) return null;
    return this.items.peek();
  }

  /**
   * Return oldest value from the queue or null if empty.
   * (Peek at the next value to be dequeue)
   * ReturnTime: O(n)
   */
  front() {
    if (this.items.isEmpty()) return null;
    return this.items.front();
  }
}



module.exports = Queue;
