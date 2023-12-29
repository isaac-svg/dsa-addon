const {Queue} = require("../lib/binding")
// console.log(Queue)


const newQueue = new Queue()


newQueue.enqueue([{sd:"sds"}])
newQueue.enqueue([{sd:"sds"}])
newQueue.enqueue([{sd:"sds"}])
console.log(newQueue.enqueue('[{sd:"sds"}]').peek())

console.log(newQueue.isEmpty())
console.log(newQueue.size())
console.log(newQueue.dequeue())
console.log(newQueue.dequeue())
console.log(newQueue.dequeue())


// console.log(newQueue.back(), "back")
console.log(newQueue.peek(), "peek")