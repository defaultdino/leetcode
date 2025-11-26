// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2966/

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> combinations;
        int target = 0;
        
        // fix `i` each iteration
        for (int i = 0; i < nums.size(); i++) {
            
            // if the previous and current number using different
            // indexes for `i` are the same, skip this iteration
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // left pointer `j` will be one step ahead of `i`
            int j = i + 1;
            // right pointer `k` will be one at the last position
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                // if the sum is smaller than our target,
                // we know we have to increase `j` pointer which works
                // since the list is sorted
                if (sum < target)
                    j++;
                // if the sum is greater than our target,
                // we know we have to decrease `k` pointer which works
                // since the list is sorted
                else if (sum > target)
                    k--;
                else {
                    combinations.push_back({ nums[i], nums[j], nums[k] });
                    k--;
                    j++;
                    // make sure previous/next and current number are not equal,
                    // but if they are keep decrementing/incrementing
                    while (j < k && nums[k] == nums[k+1]) { k--; }
                    while (j < k && nums[j] == nums[j-1]) { j++; }
                }
            }
        }
        
        return combinations;
    }
};