// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2963/

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
      int maxArea = 0;
      int left = 0, right = height.size() - 1;      
      
      while (left < right) {
        // always move pointer with the "shortest line"
        int area;
        if (height[left] < height[right])
          area = height[left] * (right - left);
        else
          area = height[right] * (right - left);

        maxArea = area > maxArea ? area : maxArea;

        if (height[left] < height[right])
          left++;
        else
          right--;
      }

      return maxArea;
    }
};