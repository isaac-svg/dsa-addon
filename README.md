# dsa-native: Native Data Structures and Algorithms

**Unleash the power of native JavaScript for efficient data manipulation and problem-solving.**

## Overview

**dsa-native** is an npm package providing native implementations of various data structures and algorithms in C++. This package offers efficient and performant implementations of commonly used data structures and algorithms for JavaScript applications, giving developers access to optimized code for handling complex data operations.

## Key Features

- **Native Performance:** Maximize speed and efficiency by avoiding external dependencies and fully utilizing JavaScript's native features.
- **Foundational Data Structures:** Access a variety of essential data structures, including:
  - VectorList
  - LinkedList
  - Stack
  - Queue
- **Sorting Algorithm:** Implement the widely used quickSort algorithm for efficient data organization.
- **Open to Contributions:** Help expand the library's functionality and contribute to its growth!

## Installation

Install the package using npm:

```bash
npm install dsa-native
```

```js
const {
  VectorList,
  LinkedList,
  Stack,
  Queue,
  quickSort,
} = require("dsa-native");

// Usage examples will be available once the methods are fully implemented.

// VectorList example
const vectorList = new VectorList();
// Perform operations with VectorList methods

// LinkedList example
const linkedList = new LinkedList();
// Perform operations with LinkedList methods

// Stack example
const stack = new Stack([]);
// Perform operations with Stack methods

// Queue example
const queue = new Queue();
// Perform operations with Queue methods

// quickSort example
const arr = [2, 1, 3, 4, 1, 2, 34, 1, 213, 2222, 34, 5, 6, 7, 8, 0];

quicksortAsync(arr, (a, b) => a > b).then((data) => console.log(data));

// Merge sort
// Merge sort methods usage will be shown once implemented
```

| Algorithm Name | Input Size | Time Taken by Native Code (seconds) | Time Taken by JS Implementation (seconds) |
| -------------- | ---------- | ----------------------------------- | ----------------------------------------- |
| QuickSort      | 10,000,000 | 4.877                               | 7.377                                     |
|                |            |                                     |                                           |
|                |            |                                     |                                           |
|                |            |                                     |                                           |

## Available Data Structures and Algorithms

**Data Structures:**

- **VectorList:** A vector based implementation of a linkedlist.
- **LinkedList:** A linear collection of nodes, providing flexibility in insertion and deletion.
- **Stack:** A LIFO (Last-In-First-Out) data structure for managing ordered operations.
- **Queue:** A FIFO (First-In-First-Out) data structure for handling sequential tasks.

**Algorithm:**

- **quickSort:** A divide-and-conquer sorting algorithm known for its efficiency.

## Contributing

`dsa-native` is open to contributions. You can contribute by implementing methods, fixing bugs, improving documentation, or suggesting enhancements. Please follow the guidelines in the CONTRIBUTING.md file.

## Documentation in Progress

Detailed documentation for individual data structures and algorithms is currently under development. Stay tuned for updates!
