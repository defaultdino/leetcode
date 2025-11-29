// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/514/

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
  bool validate(TreeNode *root, int *&previous) {
    if (!root)
      return true;
    
    bool validLeft = validate(root->left, previous);
    if (!previous || (previous && root->val > *previous))
      previous = &(root->val);
    else
      return false;
    bool validRight = validate(root->right, previous);

    return validLeft && validRight;
  }

public:
    bool isValidBST(TreeNode* root) {
      int *previous = nullptr;
      return validate(root, previous);
    }
};