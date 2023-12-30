const { MergeSort } = require("../lib/binding");

async function sort(array) {
  const data = await MergeSort(array);
  //   console.log(data);
}

const testArray = Array.from({ length: 10000000 }, () => Math.random());

sort(testArray);
