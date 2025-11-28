// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2972/

#include <string>
#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
      std::stack<char> stack;
      std::unordered_map<char, char> map = {
        { '}', '{' },
        { ']', '[' },
        { ')', '(' }
      };

      for (const char &c : s) {
        if (map.count(c)) {

          if (stack.empty())
            return false;

          else if (stack.top() != map[c])
            return false;

          else {
            stack.pop();
            continue;
          }
        }
        stack.push(c);
      }

      return stack.empty();
    }
};