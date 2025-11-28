// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/902/

#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
      // base case (t cannot be larger than s)
      if (t.size() > s.size())
        return "";

      // define pointers
      int left = 0;
      int right = 0;

      // define index pointers for substring with smallest length
      int minLeft = 0;
      int minRight = INT_MAX;

      // create one map for target values (required LEAST amounts)
      // create one map of counts of current characters
      std::unordered_map<char, int> targets;
      std::unordered_map<char, int> window;

      // populate target map
      for (char c : t) {
        targets[c]++;
      }

      // define formed and required
      int formed = 0;
      int required = targets.size();


      // while right pointer is smaller than the end
      while (right < s.size()) {
        // 1. add character from right
        window[s[right]]++;

        // 2. if current character is required and our count of it in the current substring is the same as in targetMap : increment formed
        if (targets.count(s[right]) && window[s[right]] == targets[s[right]])
          formed++;
        
        // 3. while formed is same as required and left pointer less than right,
        while (formed == required && left <= right) {
          // 3.1 store new substring indices
          if ((right - left + 1) < minRight) {
            minLeft = left;
            minRight = right - left + 1;
          }

          // 3.2 remove the left-most char from windowmap (decr.) and if its removal
          // causes its windowMap ref to be less than targetMap, decr. formed
          window[s[left]]--;
          if (targets.count(s[left]) && window[s[left]] < targets[s[left]])
            formed--;
          left++;
        }
        right++;
      }
      return minRight == INT_MAX ? "" : s.substr(minLeft, minRight);
    }
};