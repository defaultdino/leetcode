#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
      int i = 0;
      int sign = 1;
      int res = 0;
      
      // as long as we have whitespaces, continue moving pointer
      while (i < s.size() && s[i] == ' ') { i++; }
      
      // if we hit a sign, assign the sign and also move pointer past it
      if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-')
          sign = -1;
        i++;
      }

      // while the char value is in the range of ASCII numbers
      while (i < s.size() && (s[i] >= '0' && s[i] <= '9')) {
        // here we only deal with positive numbers, sign happens on return only
        if ((res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7)))
          return sign == -1 ? INT_MIN : INT_MAX;
        res = 10 * res + (s[i++] - '0');
      }

      return res * sign;
    }
};