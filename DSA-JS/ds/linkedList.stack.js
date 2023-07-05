const LinkedListWithTail = require("./linkedList.tail");
//stack
class LinkedListStack {
  constructor() {
    this.list = new LinkedListWithTail();
  }

  push(value) {
    this.list.prepend(value);
  }

  pop() {
    return this.list.removeFromFront();
  }

  peek() {
    return this.list.head.value;
  }

  isEmpty() {
    return this.list.isEmpty();
  }

  getSize() {
    return this.list.getSize();
  }

  print() {
    return this.list.print();
  }
}

const stack = new LinkedListStack();
stack.push(1);
stack.push(2);
stack.peek();
console.log(stack.getSize());
