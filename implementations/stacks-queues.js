class Node {
  next = null;
  constructor(data) {
    this.data = data;
  }
}

class Queue {
  head = null;
  tail = null;
  isEmpty = () => this.head === null;
  peek = () => this.head.data;
  add = (data) => {
    const node = new Node(data);
    if (this.tail) {
      this.tail.next = node;
    }
    this.tail = node;
    if (!this.head) {
      this.head = node;
    }
  };
  remove = () => {
    const data = this.head.data;
    this.head = this.head.next;
    if (!this.head) {
      this.tail = null;
    }
    return data;
  };
}

class Stack {
  top = null;
  isEmpty = () => this.top === null;
  peek = () => this.top.data;
  push = (data) => {
    const node = new Node(data);
    node.next = this.top;
    this.top = node;
  };
  pop = () => {
    const data = this.top.data;
    this.top = this.top.next;
    return data;
  };
}
