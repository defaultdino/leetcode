// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2968/

#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // needle.size() is our window size
        if (needle.size() > haystack.size())
            return -1;
        
        int left = 0;
        
        while (left <= haystack.size() - needle.size()) {
            if (haystack.substr(left, needle.size()) == needle) {
                return left;
            }
            left++;
        }
        
        return -1;
    }
};