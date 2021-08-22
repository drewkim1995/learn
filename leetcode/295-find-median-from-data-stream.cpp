// https://leetcode.com/problems/find-median-from-data-stream/

// TWO HEAP INTUITION : We have to consider middle element/s where all other elements are sorted as data stream come.
// Heaps come into picture with less time complexity to achieve this.
// So, we keep two heaps, one min heap and one max heap and keep a track of middle elements by balancing each heap.

class MedianFinder {
private:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > minHeap;    // Elements in decreasing order (max to min)
	priority_queue<int> maxHeap;                                // Elements in increasing order (min to max)

public:
    void addNum(int num) {
        if (maxHeap.empty() or maxHeap.top() > num) {
			maxHeap.push(num);
		} else {
			minHeap.push(num);
		}

		if (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} else if (minHeap.size() > maxHeap.size() + 1) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
			if (maxHeap.empty()) {
				return 0;
			} else {
				double avg = (maxHeap.top() + minHeap.top()) / 2.0;
				return avg;
			}

		} else {
			return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
		}
    }
};