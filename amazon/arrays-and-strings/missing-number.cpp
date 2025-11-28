// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2971/

#include <vector>
#include <numeric>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return (n * (n + 1) / 2) - std::accumulate(nums.begin(), nums.end(), 0);
    }
};
