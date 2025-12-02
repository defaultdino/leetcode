// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/507/

#include <queue>

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
  bool isMirror(TreeNode* first, TreeNode* second) {
    if (!first && !second)
      return true; // symmetric since both have no nodes mirroring
    if (!first || !second)
      return false; // one child exists, so asymmetric at this point

    return (first->val == second->val) 
      && isMirror(first->left, second->right) 
      && isMirror(first->right, second->left);
  }
public:
    bool isSymmetric(TreeNode* root) {
      if (!root)
        return true;
      return isMirror(root->left, root->right);
    }
};