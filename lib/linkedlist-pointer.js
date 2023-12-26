const { PointerList} = require("../build/Release/dsa-native")
 
/**
 * Class for working with linked lists, implemented using a native C++ addon.
 * @class LinkedList
 */
class LinkedList {
  /**
   * Creates a new LinkedList instance.
   * @constructor
   */
  constructor() {
    /**
     * @type {PointerList}
     * @private
     */
    this.list = new PointerList();
  }

  /**
   * Adds a new node to the head of the list.
   * @param {any} val - The value to add to the head.
   * @returns {void}
   * @throws {Error} If JSON stringification fails.
   * @timeComplexity O(1)
   */
  addHead(val) {
    this.list.addHead(JSON.stringify(val));
  }

  /**
   * Adds a new node to the tail of the list.
   * @param {any} val - The value to add to the tail.
   * @returns {void}
   * @throws {Error} If JSON stringification fails.
   * @timeComplexity O(1)
   */
  addTail(val) {
    this.list.addTail(JSON.stringify(val));
  }

  /**
   * Gets the current size of the list.
   * @returns {number} The number of nodes in the list.
   * @timeComplexity O(1)
   */
  size() {
    return this.list.size();
  }

  /**
   * Deletes the first node with the specified value.
   * @param {any} val - The value to delete.
   * @returns {any|null} The deleted node's value or null if not found.
   * @timeComplexity O(n) - Linear search for the value.
   */
  deleteNode(val) {
    return JSON.parse(this.list.deleteNode(JSON.stringify(val)));
  }

  /**
   * Deletes all nodes in the list.
   * @returns {void}
   * @timeComplexity O(n) - Iterates through each node.
   */
  deleteNodes() {
    this.list.deleteNodes();
  }

  /**
   * Gets the value of the first node (head).
   * @returns {any} The value of the head node or null if the list is empty.
   * @timeComplexity O(1)
   */
  peek() {
    return JSON.parse(this.list.peek());
  }

  /**
   * Reverses the order of nodes in the list.
   * @returns {void}
   * @timeComplexity O(n) - Iterates through and swaps links.
   */
  reverse() {
    this.list.reverse();
  }

  /**
   * Inserts a new node in sorted order (assuming ascending order).
   * @param {any} val - The value to insert.
   * @returns {void}
   * @throws {Error} If JSON stringification fails.
   * @timeComplexity O(n) - Linear search for insertion point.
   */
  sortedInsert(val) {
    this.list.sortedInsert(JSON.stringify(val));
  }
}

module.exports = LinkedList;
