const { QuickSort } = require("../build/Release/dsa-native");

// function quickSort(arr = [], func = undefined) {
//   return new QuickSort().sort(arr, func);
// }

async function quicksortAsync(arr = [], func = undefined) {
  return new QuickSort().quicksortAsync(arr, func);
}

module.exports = { quicksortAsync };
