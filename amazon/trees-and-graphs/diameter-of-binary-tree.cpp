// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/2985/

#include <queue>
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
  int diameter = 0;
public:
    // returns the height of a binary tree using DFS
    int getHeight(TreeNode* root) {
      if (!root)
        return 0;
      
      int leftSubtreeHeight = getHeight(root->left);
      int rightSubtreeHeight = getHeight(root->right);

      diameter = std::max(leftSubtreeHeight + rightSubtreeHeight, diameter);

      return std::max(leftSubtreeHeight, rightSubtreeHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
      getHeight(root);
      return diameter;
    }
};