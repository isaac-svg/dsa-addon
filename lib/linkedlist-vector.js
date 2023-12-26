const {LinkedList} = require("../build/Release/dsa-native")
 
/**
 * Class for working with vector-like lists, implemented using a LinkedList.
 * @class VectorList
 */
class VectorList {
  /**
   * Creates a new VectorList instance.
   * @constructor
   */
  constructor() {
    /**
     * @type {LinkedList}
     * @private
     */
    this.list = new LinkedList();
  }

  /**
   * Sets the value at a specific index.
   * @param {number} index - The index to set the value at.
   * @param {any} val - The value to set.
   * @returns {void}
   * @throws {RangeError} If the index is out of bounds.
   * @throws {Error} If JSON stringification fails.
   * @timeComplexity O(n) - Linear search to reach the index.
   */
  set(index, val) {
    this.list.set(index, JSON.stringify(val));
  }

  /**
   * Inserts a new value at the beginning of the list.
   * @param {any} val - The value to insert.
   * @returns {void}
   * @throws {Error} If JSON stringification fails.
   * @timeComplexity O(1)
   */
  unshift(val) {
    this.list.unshift(JSON.stringify(val));
  }

  /**
   * Gets the current size of the list.
   * @returns {number} The number of elements in the list.
   * @timeComplexity O(1)
   */
  size() {
    return this.list.size();
  }

  /**
   * Gets the value at a specific index.
   * @param {number} index - The index of the value to retrieve.
   * @returns {any} The value at the specified index.
   * @throws {RangeError} If the index is out of bounds.
   * @timeComplexity O(n) - Linear search to reach the index.
   */
  get(index) {
    return JSON.parse(this.list.get(index));
  }

  /**
   * Removes and returns the value at the end of the list.
   * @returns {any} The removed value or null if the list is empty.
   * @timeComplexity O(1)
   */
  pop() {
    return JSON.parse(this.list.pop());
  }

  /**
   * Adds a new value to the end of the list.
   * @param {any} val - The value to add.
   * @returns {void}
   * @throws {Error} If JSON stringification fails.
   * @timeComplexity O(1)
   */
  push(val) {
    this.list.push(JSON.stringify(val));
  }
}

module.exports = VectorList;

    

