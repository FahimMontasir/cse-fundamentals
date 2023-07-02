class CircularQueue {
  constructor(capacity) {
    this.items = new Array(capacity);
    this.capacity = capacity;
    this.currentLength = 0;
    this.rear = -1;
    this.front = -1;
  }

  isFull() {
    return this.currentLength === this.capacity;
  }

  isEmpty() {
    return this.currentLength === 0;
  }

  enqueue(elem) {
    if (!this.isFull()) {
      this.rear = (this.rear + 1) % this.capacity;
      this.items[this.rear] = elem;
      this.currentLength += 1;

      if (this.front === -1) {
        this.front = this.rear;
      }
    }
  }

  dequeue() {
    if (this.isEmpty()) {
      return null;
    }
    const item = this.items[this.front];
    this.items[this.front] = null;
    this.front = (this.front + 1) % this.capacity;
    this.currentLength -= 1;
    if (this.isEmpty()) {
      this.front = -1;
      this.rear = -1;
    }
    return item;
  }

  peek() {
    if (!this.isEmpty()) {
      return this.items[this.front];
    }
    return null;
  }

  print() {
    if (this.isEmpty()) {
      console.log("Queue is empty!!");
    } else {
      console.log(this.items.toString());
    }
  }
}

const circularQueue = new CircularQueue(5);

circularQueue.enqueue(10);
circularQueue.enqueue(5);
circularQueue.enqueue(20);
circularQueue.enqueue(1);
circularQueue.enqueue(50);

circularQueue.dequeue();
circularQueue.dequeue();
circularQueue.dequeue();

circularQueue.enqueue(0);
circularQueue.enqueue(5);
circularQueue.enqueue(9);

console.log(circularQueue.peek());

circularQueue.print();
