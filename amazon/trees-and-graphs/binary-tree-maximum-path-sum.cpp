// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/2981/

#include <numeric>

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
  int maxGlobalSum = INT_MIN;

  int dfs(TreeNode* node) {
    if (!node)
      return 0;

    int rightGain = std::max(dfs(node->left), 0);
    int leftGain = std::max(dfs(node->right), 0);

    int currentMax = node->val + rightGain + leftGain;

    this->maxGlobalSum = std::max(this->maxGlobalSum, currentMax);

    return node->val + std::max(leftGain, rightGain);
  }
public:
  int maxPathSum(TreeNode* root) {
    this->dfs(root);
    return this->maxGlobalSum;
  }
};