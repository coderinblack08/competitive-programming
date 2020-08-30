class Node {
  next = null;
  constructor(value) {
    this.head = value;
  }
}

class LinkedList {
  head = null;
  append = (value) => {
    if (!this.head) {
      this.head = new Node(value);
      return;
    }
    let current = this.head;
    while (current.next) {
      current = current.next;
    }
    current.next = new Node(value);
  };
  prepend = (value) => {
    const newHead = new Node(value);
    newHead.next = this.head;
    this.head = newHead;
  };
  deleteWithValue = (value) => {
    if (!this.head) return;
    if (head.head === data) {
      head = head.next;
      return;
    }
    let current = this.head;
    while (current.next) {
      if (current.next.head === value) {
        current.next = current.next.next;
        return;
      }
      current = current.next;
    }
  };
  showAsArray = () => {
    const resultArray = [];
    let current = this.head;
    while (current.next) {
      resultArray.push(current.head);
      current = current.next;
    }
    resultArray.push(current.head);
    return resultArray;
  };
}

const linkedList = new LinkedList();
linkedList.append(1);
linkedList.append(2);
linkedList.prepend(3);
console.log(linkedList.showAsArray());
