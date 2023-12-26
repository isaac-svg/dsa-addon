const assert = require("assert");
const {LinkedList} = require("../lib/binding")

test('Creates a new LinkedList instance with size 0', () => {
    const list = new LinkedList();
    expect(list.size()).toBe(0);
  });

  
  test('Adds a node to the head of an empty list', () => {
    const list = new LinkedList();
    list.addHead(10);
    expect(list.size()).toBe(1);
    expect(list.peek()).toBe(10);
  });
  
  test('Adds multiple nodes to the head', () => {
    const list = new LinkedList();
    list.addHead(30);
    list.addHead(20);
    list.addHead(10);
    expect(list.size()).toBe(3);
    expect(list.peek()).toBe(10);
  });
  
  test('Throws an error if JSON stringification fails', () => {
    const list = new LinkedList();
    expect(() => list.addHead({})).toThrowError(Error);
  });
  