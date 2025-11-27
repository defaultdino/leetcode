// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2973/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class Solution {
private:
  bool isValid(char c) {
    c = std::tolower(c);
    return (c >= 'a' && c <= 'z');
  }

public:
    std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
        std::unordered_map<std::string, int> occurences;
        std::unordered_set<std::string> bannedSet(banned.begin(), banned.end());

        int right = 0;
        int maxCount = 0;
        std::string mostCommonWord = "";

        while (right < paragraph.size()) {
          while (right < paragraph.size() && !isValid(paragraph[right])) { right++; }
          if (right >= paragraph.size()) break;

          std::string word = "";
          while (right < paragraph.size() && isValid(paragraph[right])) { 
            word += std::tolower(paragraph[right]);
            right++;
          }

          if (bannedSet.count(word)) continue;

          occurences[word]++;

          if (occurences[word] > maxCount) {
            maxCount = occurences[word];
            mostCommonWord = word;
          }
        }

        return mostCommonWord;
    }
};
