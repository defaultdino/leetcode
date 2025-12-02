// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/506/

#include <vector>
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
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;

        if (!root)
          return result;

        std::queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
          int levelSize = q.size();
          result.push_back({});
          while (levelSize != 0) {
            TreeNode* curr = q.front();
            q.pop();

            result[level].push_back(curr->val);

            // check if this node has any children, push them to the queue
            // we will iterate over them on the next level
            if (curr->left)
              q.push(curr->left);
            if (curr->right)
              q.push(curr->right);
            levelSize--;
          }
          level++;
        }
      return result;
    }
};