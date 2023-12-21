const { PointerList} = require("../build/Release/dsa-native")
 
// console.log(addon)
function LinkedList() {

    
   this.list = new PointerList()
    
    this.addHead = (val)=>{
           return  this.list.addHead(JSON.stringify(val))
        }
    
        this.addTail = (val)=>{
          return  this.list.addTail(JSON.stringify(val))
        }
    
        this.size = () =>{
            return this.list.size()
        }

        this.deleteNode = (val) =>{
            return JSON.parse(this.list.deleteNode(val))
        }

        this.deleteNodes = () =>{
          return this.list.deleteNodes()
        }

        this.peek = () =>{
          return this.list.peek()
        }

        this.reverse = () =>{
            return this.list.reverse()
          }
          this.sortedInsert = (val) =>{
            return this.list.sortedInsert()
          }

    
}

module.exports = LinkedList
    

