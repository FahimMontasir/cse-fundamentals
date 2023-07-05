const LinkedListWithTail = require("./linkedList.tail");

class LinkedListQueue {
  constructor() {
    this.list = new LinkedListWithTail();
  }
  enqueue(value) {
    this.list.append(value);
  }
  dequeue() {
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

const queue = new LinkedListQueue();

queue.enqueue(10);
queue.enqueue(5);
queue.enqueue(0);

queue.print();
