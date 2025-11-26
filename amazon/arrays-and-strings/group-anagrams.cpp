// https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2970/

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (int i = 0; i < strs.size(); ++i) {
            std::string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(strs[i]);
        }
        
        for (auto const &x : map) {
            res.push_back(x.second);
        }
        
        return res;
    }
};