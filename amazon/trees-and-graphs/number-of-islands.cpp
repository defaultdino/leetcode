// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/894/

#include <vector>
#include <unordered_map>

class Solution {
private:

  bool isOutOfBounds(int rowSize, int colSize, int i, int j) {
    return i < 0 || j < 0 || i > rowSize - 1 || j > colSize - 1;
  }

  bool isIsland(char c) { return c == '1'; }

  void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
    if (isOutOfBounds(grid.size(), grid[0].size(), i, j) || !isIsland(grid[i][j]))
      return;

    // mark the land of the island as discovered
    grid[i][j] = '0';
    
    dfs(grid, i + 1, j); // down
    dfs(grid, i, j + 1); // right
    dfs(grid, i - 1, j); // up
    dfs(grid, i, j - 1); // left

  }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
      if (grid.empty() || grid[0].empty())
        return 0;
      
      int islands = 0;
      int rowSize = grid.size();
      int colSize = grid[0].size();
      
      for (int i = 0; i < rowSize; ++i)
        for (int j = 0; j < colSize; ++j) {
          if (grid[i][j] == '1') {
            islands++;
            dfs(grid, i, j);
          }
        }
          
      return islands;
    }
};