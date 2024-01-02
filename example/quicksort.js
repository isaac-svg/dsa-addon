const { quicksortAsync, quickSort } = require("../lib/binding");

const arr = [2, "1", 3, "4", 1, 2, 34, 1, "213", 2222, 34, 5, 6, 7, 8, "0"];

quicksortAsync(arr, (a, b) => a > b).then((data) => console.log(data));

console.log(quickSort(arr));
