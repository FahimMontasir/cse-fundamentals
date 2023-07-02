class Queue {
  constructor() {
    this.items = {};
    this.rear = 0;
    this.front = 0;
  }

  enqueue(elem) {
    // O(1)
    this.items[this.rear] = elem;
    this.rear++;
  }

  dequeue() {
    // O(1)
    const item = this.items[this.front];
    delete this.items[this.front];
    this.front++;

    return item;
  }

  isEmpty() {
    return this.rear - this.front === 0;
  }

  peek() {
    if (!this.isEmpty()) {
      return this.items[this.front];
    }
    return null;
  }

  size() {
    return this.rear - this.front;
  }

  print() {
    console.log(this.items);
  }
}

const queue = new Queue();

console.log(queue.isEmpty());

queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);

console.log(queue.dequeue());

queue.enqueue(40);
queue.dequeue();

console.log(queue.size());

queue.print();

// not  an optimized solution
// class Queue {
//   constructor() {
//     this.items = [];
//   }

//   enqueue(elem) {
//     this.items.push(elem); // O(1)
//   }

//   dequeue() {
//     return this.items.shift(); //O(n)
//   }

//   isEmpty() {
//     return this.items.length === 0;
//   }

//   peek() {
//     if (!this.isEmpty()) {
//       return this.items[0];
//     }
//     return null;
//   }

//   size() {
//     return this.items.length;
//   }

//   print() {
//     console.log(this.items.toString());
//   }
// }

// const queue = new Queue();
