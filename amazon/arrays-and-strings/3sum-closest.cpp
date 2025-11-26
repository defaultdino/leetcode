// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2967/

#include <vector>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int leastDistance = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int currentSum = nums[i] + nums[j] + nums[k];
                int currentDistance = target - currentSum;
                
                if (std::abs(currentDistance) < leastDistance) {
                    closestSum = currentSum;
                    leastDistance = std::abs(currentDistance);                    
                }
                
                if (currentSum < target)
                    j++;
                else if (currentSum > target)
                    k--;
                else
                    return currentSum;
            }
        }
        return closestSum;
    }
};