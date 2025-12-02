// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/2982/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

/*
  * this is a shortest path problem in an unweighted graph. Each word represents a node, 
  * and two words are connected if they differ by exactly one letter. Since we want the
  * minimum number of transformations, we need to find the shortest path from beginWord to endWord.
  * 
  * Using BFS for this problem is the best option.
*/

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::queue<std::string> words;
        words.push(beginWord);

        std::unordered_set<std::string> dictionary(wordList.begin(), wordList.end());
        int chainLen = 0;
        int m = beginWord.length();

        while (!words.empty()) {
          chainLen++;
          int len = words.size();
          for (int i = 0; i < len; ++i) {
            std::string currentWord = words.front();
            words.pop();

            for (int j = 0; j < m; ++j) {
              char originalChar = currentWord[j];
              for (char k = 'a'; k <= 'z'; ++k) {
                currentWord[j] = k;

                if (dictionary.find(currentWord) == dictionary.end())
                  continue;

                if (currentWord == endWord)
                  return chainLen + 1;

                dictionary.erase(currentWord);
                words.push(currentWord);
              }
              currentWord[j] = originalChar;
            }
          }
        }
        
      return 0;
    }
};