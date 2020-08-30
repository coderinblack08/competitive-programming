class Heap {
  items = [];
  leftChildIndex = (parentIndex) => 2 * parentIndex + 1;
  rightChildIndex = (parentIndex) => 2 * parentIndex + 2;
  parentIndex = (childIndex) => ~~((childIndex - 1) / 2);

  hasLeftChild = (parentIndex) =>
    this.leftChildIndex(parentIndex) > this.items.length;
  hasRightChild = (parentindex) =>
    this.rightChildIndex(this.parentIndex) > this.items.length;
  hasParent = (childIndex) => this.parentIndex(childIndex) >= 0;

  leftChild = (parentIndex) => this.items[this.leftChildIndex(parentIndex)];
  rightChild = (parentIndex) => this.items[this.rightChildIndex(parentIndex)];
  parent = (childIndex) => this.items[this.parentIndex(childIndex)];

  swap = (index1, index2) =>
    ([this.items[index1], this.items[index2]] = [
      this.items[index2],
      this.items[index1],
    ]);

  heapifyUp = () => {
    let index = this.items.length - 1;
    while (this.hasParent(index) && this.parent(index) > this.items[index]) {
      this.swap(index, this.parentIndex(index));
      index = this.parentIndex(index);
    }
  };

  heapifyDown = () => {
    let index = 0;
    while (this.hasLeftChild(index)) {
      let smallerChildIndex = this.leftChildIndex(index);
      if (
        this.hasRightChild(index) &&
        this.rightChild(index) < this.leftChild(index)
      ) {
        smallerChildIndex = this.rightChildIndex(index);
      }
      if (this.items[index] < this.items[smallerChildIndex]) {
        break;
      } else {
        this.swap(index, smallerChildIndex);
      }
      index = smallerChildIndex;
    }
  };

  peek = () => (this.items.length !== 0 ? this.items[0] : undefined);
  pull = () => {
    if (this.items.length === 0) return undefined;
    this.items.shift();
    this.heapifyDown();
  };
  add = (element) => {
    this.items.push(element);
    this.heapifyUp();
  };
}
