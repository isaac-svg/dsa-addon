const {VectorList,LinkedList} = require("../lib/binding")


const newList = new LinkedList()
console.log(newList)
const vList = new VectorList()
console.log(newList.addHead([{hello:"world"},12, true]))

console.log(newList.addHead("start"))
console.log(newList.size())
console.log(newList.addHead("asdsfdsfds"))
newList.addHead("My name is Isaac")
console.log(newList.addHead({"end":"sdsdsd"}))
console.log(newList.addHead([{hello:"world"},12, true]))

console.log(newList.peek(), "pp1")
console.log(newList.peek(), "pp1")
console.log(newList.peek(), "pp1")
console.log(newList.peek(), "pp1")
console.log(newList.peek(), "pp1")
console.log(newList.peek(), "pp1")
console.log(newList.peek(), "pp1")
console.log(vList.push(["sdfsdfds;", {ll:"asdasda"}]))
console.log(vList.push(["sdfsdfds;"]))
console.log(vList.push(["sdfsdfds;"]))
console.log(vList.push(["sdfsdfds;"]))
console.log(vList.set(1,"kwame is at 1"), "set")
console.log(vList.get(1), "get")

