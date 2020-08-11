#include <vector>
using namespace std;

/*
Implement a MinHeap class that supports:

- Building a Min Heap from an input array of integers.
- Inserting integers in the heap.
- Removing the heap's minimum / root value.
- Peeking at the heap's minimum / root value.
- Sifting integers up and down the heap, which is to be used when inserting and removing values.
Note that the heap should be represented in the form of an array.

If you're unfamiliar with Min Heaps, we recommend watching the Conceptual Overview section of this question's video explanation before starting to code.

Sample Usage
array = [48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41]

// All operations below are performed sequentially.
MinHeap(array): - // instantiate a MinHeap (calls the buildHeap method and populates the heap)
buildHeap(array): - [-5, 2, 6, 7, 8, 8, 24, 391, 24, 56, 12, 24, 48, 41]
insert(76): - [-5, 2, 6, 7, 8, 8, 24, 391, 24, 56, 12, 24, 48, 41, 76]
peek(): -5
remove(): -5 [2, 7, 6, 24, 8, 8, 24, 391, 76, 56, 12, 24, 48, 41]
peek(): 2
remove(): 2 [6, 7, 8, 24, 8, 24, 24, 391, 76, 56, 12, 41, 48]
peek(): 6
insert(87): - [6, 7, 8, 24, 8, 24, 24, 391, 76, 56, 12, 41, 48, 87]
*/

class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int> &vector) {
    int parent = (vector.size() - 2) / 2;
		for(int cur = parent; cur >= 0; cur--)
			siftDown(cur, vector.size() - 1, vector);
    return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    int left  = 2 * currentIdx + 1;

		while(left <= endIdx)
		{
			int right = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
			int idxSwap;
			if(right != -1 && heap[right] < heap[left])
				idxSwap = right;
			else
				idxSwap = left;
			if(heap[idxSwap] < heap[currentIdx])
			{
				swap(heap[idxSwap], heap[currentIdx]);
				currentIdx = idxSwap;
				left  = 2 * currentIdx + 1;
			} else {
				return;
			}
		}
  }

  void siftUp(int currentIdx, vector<int> &heap) {
    int parent = (currentIdx - 1) / 2;
		while(parent > 0 && heap[parent] > heap[currentIdx]){
			swap(heap[parent], heap[currentIdx]);
			currentIdx = parent;
			parent = (currentIdx - 1) / 2;
		}
  }

  int peek() {
    return heap[0];
  }

  int remove() {
    swap(heap[0], heap[heap.size() - 1]);
		int min = heap.back();
		heap.pop_back();
		siftDown(0, heap.size() - 1, heap);
    return min;
  }

  void insert(int value) {
    heap.push_back(value);
		siftUp(heap.size() - 1, heap);
  }
};
