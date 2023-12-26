const {Queue: NativeQueue} = require('../build/Release/dsa-native');



/**
 * Class for working with queues, implemented using a native C++ addon.
 * @class Queue
 */
class Queue {
    /**
     * Creates a new Queue instance.
     * @constructor
     * @param {iterable<any>} [iterable] - Optional iterable of initial values.
     */
    constructor() {
      /**
       * @type {NativeQueue}
       * @private
       */
      this.items = new NativeQueue();
    }
  
    /**
     * Adds a new element to the back of the queue.
     * @param {any} item - The item to add.
     * @returns {Queue} The queue instance to allow chaining.
     * @timeComplexity O(1)
     */
    enqueue(item) {
       this.items.enqueue(JSON.stringify(item));
      return this
    }
  
    /**
     * Removes and returns the element at the front of the queue.
     * @returns {any} The removed value or null if the queue is empty.
     * @timeComplexity O(1)
     */
    dequeue() {
      return JSON.parse(this.items.dequeue());
    }
  
    /**
     * Gets the current size of the queue.
     * @returns {number} The number of elements in the queue.
     * @timeComplexity O(1)
     */
     size() {
      return this.items.size();
    }
  
    /**
     * Checks if the queue is empty.
     * @returns {boolean} True if the queue is empty, false otherwise.
     * @timeComplexity O(1)
     */
    isEmpty() {
      return this.items.isEmpty();
    }
  
    /**
     * Returns the most recent value (at the back) without removing it, or null if empty.
     * @returns {any} The most recent value or null if the queue is empty.
     * @timeComplexity O(1)
     */
    peek() {
      if (this.items.isEmpty()) return null;
      return this.items.peek();
    }
  
    /**
     * Returns the oldest value (at the front) without removing it, or null if empty.
     * @returns {any} The oldest value or null if the queue is empty.
     * @timeComplexity Likely O(n) (depends on native implementation)
     */
    back() {
      if (this.items.isEmpty()) return null;
      return JSON.parse(this.items.back());
    }
  
    /**
     * Removes all elements from the queue.
     * @returns {void}
     * @timeComplexity O(n)
     */
    // clear() {
    //   return this.items.clear();
    // }
  }
  
  module.exports = Queue;
  