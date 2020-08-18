class MinHeap {
  constructor() {
    this.heap = new Array(1).fill(null);
  }
  insert(num) {
    this.heap.push(num);
    if (this.heap.length > 2) {
      let index = this.heap.length - 1;
      const parent = Math.floor(index / 2);
      while (this.heap[index] < this.heap[parent]) {
        if (index >= 1) {
          // Swap parent and child
          [this.heap[parent], this.heap[index]] = [
            this.heap[index],
            this.heap[parent],
          ];
          if (Math.floor(parent) > 1) {
            index = parent;
          } else {
            break;
          }
        }
      }
    }
  }
}

const Heap = new MinHeap();
Heap.insert(1);
Heap.insert(5);
Heap.insert(2);
Heap.insert(6);
Heap.insert(3);
console.log(Heap.heap);

export default MinHeap;
