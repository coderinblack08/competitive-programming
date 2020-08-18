class Node {
  constructor(element) {
    this.element = element;
    this.next = null;
  }
}

class LinkedList {
  length = 0;
  head = null;
  size = () => this.length;
  isEmpty = () => this.length === 0;
  add = (element) => {
    const node = new Node(element);
    if (this.head) {
      let currentNode = this.head;
      while (currentNode.next) {
        currentNode = currentNode.next;
      }
      currentNode.next = node;
    } else {
      this.head = node;
    }
    this.length++;
  };
  remove = (element) => {
    let currentNode = this.head,
      previous;
    if (currentNode.element === element) {
      this.head = currentNode.next;
    } else {
      while (currentNode.element != element) {
        previous = currentNode;
        currentNode = currentNode.next;
      }
      previous.next = currentNode.next;
    }
    this.length--;
  };
  indexOf = (element) => {
    let currentNode = this.head,
      index = -1;
    while (currentNode) {
      index++;
      if (currentNode.element === element) {
        return index;
      }
      currentNode = currentNode.next;
    }
    return -1;
  };
  elementAt = (index) => {
    let currentNode = this.head,
      count = 0;
    while (count < index) {
      count++;
      currentNode = currentNode.next;
    }
    return currentNode.element;
  };
  addAt = (index, element) => {
    let node = new Node(element),
      currentNode = this.head,
      previous,
      current = 0;
    if (index > this.length) {
      return false;
    }
    if (index === 0) {
      node.next = currentNode;
      this.head = node;
    } else {
      while (current < index) {
        current++;
        previous = currentNode;
        currentNode = currentNode.next;
      }
      node.next = currentNode;
      previous.next = node;
    }
    this.length++;
  };
  removeAt = (index, element) => {
    let currentNode = this.head,
      previous,
      current = 0;
    if (index < current || index > this.length) {
      return null;
    }
    if (index === 0) {
      this.head = currentNode.next;
    } else {
      while (current < index) {
        currentNode++;
        previous = currentNode;
        currentNode = currentNode.next;
      }
      previous.next = currentNode.next;
    }
    this.length--;
    return currentNode.element;
  };
}
