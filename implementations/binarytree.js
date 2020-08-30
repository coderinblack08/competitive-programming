class Node {
  left = null;
  right = null;
  constructor(data) {
    this.data = data;
  }
  insert = (value) => {
    if (value <= this.data) {
      if (this.left === null) {
        this.left = new Node(value);
      } else {
        this.left.insert(value);
      }
    } else {
      if (this.right === null) {
        this.right = new Node(value);
      } else {
        this.right.insert(value);
      }
    }
  };
  contains = (value) => {
    if (value === this.data) return true;
    if (value < this.data) {
      if (this.left === null) return false;
      return this.left.contains(value);
    } else {
      if (this.right === null) return false;
      return this.right.contains(value);
    }
  };
  inOrder = () => {
    if (this.left !== null) {
      this.left.inOrder();
    }
    console.log(this.data);
    if (this.right !== null) {
      this.right.inOrder();
    }
  };
}

const node = new Node(0);
[1, 5, 4].forEach((e) => node.insert(e));
console.log(node.inOrder());
