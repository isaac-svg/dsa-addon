const addon = require("../build/Release/dsa-native")
 

function LinkedList() {

    
   this.list = new addon.LinkedList()
    
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

module.exports = LinkedList
    

