const {LinkedList, PointerList} = require("../build/Release/dsa-native")
 
// console.log(addon)
function VectorList() {

    
   this.list = new LinkedList()
    
    this.set = (val)=>{
           return  this.list.set(val)
        }
    
        this.unshift = (val)=>{
          return  this.list.unshift(val)
        }
    
        this.size = () =>{
            return this.list.size()
        }

        this.get = (val) =>{
            return JSON.parse(this.list.get(val))
        }

        this.pop = () =>{
          return this.list.pop()
        }

        this.push = (val) =>{
          return this.list.push(JSON.stringify(val))
        }

    
}

module.exports = VectorList
    

