const { MergeSort: nativeMerge } = require("../build/Release/dsa-native");

async function MergeSort(array) {
  return new nativeMerge().bubbleSort(array);
}

module.exports = {
  MergeSort,
};
