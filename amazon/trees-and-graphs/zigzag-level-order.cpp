// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/2980/

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  // by default we insert at the end, but if `level` is odd then we insert into beginning
  void traverse(TreeNode *root, std::vector<std::vector<int>>& result, int level) {
    if (!root)
      return;

    if (result.size() <= level)
      result.push_back({});

    if (level % 2) {
      result[level].insert(result[level].begin(), root->val);
    } else {
      result[level].push_back(root->val);
    }

    traverse(root->left, result, level + 1);
    traverse(root->right, result, level + 1);
  }
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
      std::vector<std::vector<int>> result;
      traverse(root, result, 0);
      return result;
    }
};