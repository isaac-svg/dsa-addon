const {Stack:stack} = require('../build/Release/dsa-native');

/**
 * Class for working with stacks, implemented using a native C++ addon.
 * @class Stack
 */
class Stack {
    /**
     * Creates a new Stack instance.
     * @constructor
     */
    constructor() {
      /**
       * @type {stack}
       * @private
       */
      this.items = new stack();
    }
  
    /**
     * Adds a new element to the top of the stack.
     * @param {any} item - The item to add.
     * @returns {Stack} The stack instance to allow chaining.
     * @timeComplexity O(1)
     */
    push(item) {
      this.items.push(JSON.stringify(item));
      return this;
    }
  
    
    /**
     * Removes and returns the element at the top of the stack.
     * @returns {any} The removed value or null if the stack is empty.
     * @timeComplexity O(1)
     */
    pop() {
      return JSON.parse(this.items.pop());
    }
  
    /**
     * Alias for `pop`.
     * @see pop
     */
    remove() {
      return this.pop();
    }
  
    /**
     * Gets the current size of the stack.
     * @returns {number} The number of elements in the stack.
     * @timeComplexity O(1)
     */
    size() {
      return this.items.size();
    }
  
    /**
     * Checks if the stack is empty.
     * @returns {boolean} True if the stack is empty, false otherwise.
     * @timeComplexity O(1)
     */
    isEmpty() {
      return this.items.isEmpty();
    }
  
    /**
     * Returns the value at the top of the stack without removing it, or null if empty.
     * @returns {any} The value at the top of the stack or null if empty.
     * @timeComplexity O(1)
     */
    peek() {
      return this.items.top();
    }
  
    /**
     * Removes all elements from the stack.
     * @returns {void}
     * @timeComplexity O(n)
     */
    clear() {
      return this.items.clear();
    }
  }
  
  module.exports = Stack;
  