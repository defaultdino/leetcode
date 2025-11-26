// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/508/

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> res;
        std::unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // 9 - 2 --> 9 - 7
            
            // we found a complement. we have the index of one value,
            // but now need to retrieve the index of the second one
            if (map.count(complement)) {
                res.push_back(map[complement]);
                res.push_back(i);
                return res;
            }
            // store --> 2 : 7
            map[nums[i]] = i;
        }
        
        return res;
    }
};