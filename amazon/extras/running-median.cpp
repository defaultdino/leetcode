// https://www.hackerrank.com/challenges/find-the-running-median/problem

#include <vector>
#include <queue>

std::vector<double> runningMedian(std::vector<int> a) {
  std::priority_queue<int> maxHeap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  std::vector<double> medians;

  for (int num : a) {
    if (maxHeap.empty() || num <= maxHeap.top())
      maxHeap.push(num);
    else
      minHeap.push(num);

    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    } else if (minHeap.size() > maxHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }

    double median;

    if (maxHeap.size() == minHeap.size())
      median = maxHeap.top() + minHeap.top() / 2.0;
    else
      median = maxHeap.top();
    
    medians.push_back(median);
  }

  return medians;
}