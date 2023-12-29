const {Stack} = require("../lib/binding")


console.log(Stack)

const stack = new Stack();

console.log(stack.push("kofu").isEmpty())
console.log(stack.push("sdfdf"))
console.log(stack.push("sdfdf"))
console.log(stack.push("sdfdf"))

console.log(stack.peek())