// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/480/

#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int firstUniqChar(std::string s) {
      std::unordered_map<char, int> frequencies;

      for (const char &c : s)
        frequencies[c]++;

      for (int i = 0; i < s.size(); ++i) {
        if (frequencies[s[i]] == 1)
          return i;
      }

      return -1;
    }
};

int main() {
  Solution *sol = new Solution();
  int firstUniqueCharIndex = sol->firstUniqChar("loveleetcode");
  std::cout << firstUniqueCharIndex << "";
  return 0;
}