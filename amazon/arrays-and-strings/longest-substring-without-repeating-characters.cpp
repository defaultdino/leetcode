// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2961/

#include <unordered_map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> lastSeenIndex;
        
        int maxLen = 0;
        int start = 0;
        
        for (int end = 0; end < s.size(); end++) {
            // has the char been seen before, and is it further than current `start`?
            if (lastSeenIndex.count(s[end]) && lastSeenIndex[s[end]] >= start) {
                // set `start` to the last known index of this char
                start = lastSeenIndex[s[end]] + 1;
            }
            // update the last seen index for this char and increase max length
            maxLen = std::max(maxLen, end - start + 1);
            lastSeenIndex[s[end]] = end;
        }
        return maxLen;
    }
};