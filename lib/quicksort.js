const  {QuickSort} = require("../build/Release/dsa-native")

console.log(QuickSort)

function quickSort (arr=[], func){

    return new QuickSort(arr).sort(func)
}


module.exports = quickSort