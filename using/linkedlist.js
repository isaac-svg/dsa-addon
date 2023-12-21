const {VectorList,LinkedList} = require("../lib/binding")


const newList = new LinkedList()

console.log(newList.addHead("start"))
console.log(newList.size())
console.log(newList.addHead("asdsfdsfds"))
console.log(newList.addHead("end"))
console.log(newList.peek(), "pp1")

console.log(newList.reverse())

console.log(newList.peek(), "pp2")


