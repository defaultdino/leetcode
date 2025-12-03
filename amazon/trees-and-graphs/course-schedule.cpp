// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/2983/

#include <vector>

/**
 * what we have to do here is essentially detect cycles in a graph. if the resulting
 * graph is a directed acyclic graph, we return true.
 */

class Solution {
public:
  bool hasCycle(
      const std::vector<std::vector<int>>& graph, 
      int u, 
      std::vector<bool>& visited, 
      std::vector<bool>& recStack
  ) {
      if (recStack[u])
          return true;
      
      if (visited[u])
          return false;
      
      visited[u] = true;
      recStack[u] = true;
      
      for (int v : graph[u])
          if (hasCycle(graph, v, visited, recStack))
              return true;
      
      recStack[u] = false;
      return false;
  }

    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {

      std::vector<std::vector<int>> graph(numCourses);
      for (const auto &prereq : prerequisites) {
        int course = prereq[0];
        int prerequisite = prereq[1];

        graph[prerequisite].push_back(course);
      }

      std::vector<bool> visitedVectors(numCourses, false);
      std::vector<bool> recStack(numCourses, false);

      for (int i = 0; i < numCourses; ++i)
        if (!visitedVectors[i] && hasCycle(graph, i, visitedVectors, recStack))
          return false;
      return true;
    }
};