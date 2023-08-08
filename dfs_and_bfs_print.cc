#include <iostream>
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
 
void dfs(TreeNode* root) {
  if(nullptr == root) return;
  // std::cout << root->val << " -> ";
  dfs(root->left);
  std::cout << root->val << " -> ";
  dfs(root->right);
}

void bfs(TreeNode* root) {
    if (root == NULL)
        return;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      std::cout << node->val << " -> ";
      q.pop();
 
      if (nullptr != node->left) q.push(node->left);
      if (nullptr != node->right) q.push(node->right);
    }
}


int print(TreeNode* root) {
  dfs(root);
  std::cout << "\n";

  bfs(root);
  std::cout << "\n";
}

int main() {
  TreeNode n0(0);
  TreeNode n1(1);
  TreeNode n5(5);
  TreeNode n9(9, &n5, &n1);
  TreeNode n4(4, &n9, &n0);
  int sum = print(&n4);
}
