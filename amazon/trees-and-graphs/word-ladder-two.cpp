// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/483/

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iostream>

class Solution {
private:
  std::unordered_map<std::string, std::unordered_set<std::string>> predecessors;
  std::vector<std::vector<std::string>> result;

  void buildPaths(std::vector<std::string>& currentPath, const std::string& beginWord, const std::string& currentWord) {
    if (currentWord == beginWord) {
      std::vector<std::string> completePath(currentPath.rbegin(), currentPath.rend());
      result.push_back(completePath);
      return;
    }

    for (const auto& predecessor : predecessors[currentWord]) {
      currentPath.push_back(predecessor);
      buildPaths(currentPath, beginWord, predecessor);
      currentPath.pop_back();
    }
  }

public:
    std::vector<std::vector<std::string>> findLadders(
      std::string beginWord, 
      std::string endWord, 
      std::vector<std::string>& wordList
    ) {
      std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
      
      if (!dict.count(endWord))
        return result;

      dict.erase(beginWord);
      
      std::unordered_map<std::string, int> dist;
      dist[beginWord] = 0;

      std::queue<std::string> q;
      q.push(beginWord);

      int level = 0;
      bool targetFound = false;

      while (!q.empty() && !targetFound) {
        level++;
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
          std::string currentWord = q.front();
          std::string originalWord = currentWord;
          q.pop();

          for (int j = 0; j < currentWord.length(); ++j) {
            char originalChar = currentWord[j];

            for (char k = 'a'; k <= 'z'; ++k) {
              currentWord[j] = k;
              std::string transformedWord = currentWord;

              if (dist.count(transformedWord) && dist[transformedWord] == level)
                predecessors[transformedWord].insert(originalWord);
              if (dict.find(transformedWord) == dict.end())
                continue;
              
              predecessors[transformedWord].insert(originalWord);
              dict.erase(transformedWord);
              q.push(transformedWord);
              dist[transformedWord] = level;

              if (endWord == transformedWord)
                targetFound = true;
            }
            currentWord[j] = originalChar;
          }
        }
      }

      if (targetFound) {
        std::vector<std::string> currentPath;
        currentPath.push_back(endWord);
        buildPaths(currentPath, beginWord, endWord);
      }

      return result;
  }
};