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
 
int dfs(TreeNode* root, int pre_sum) {
  if(nullptr == root) return 0;
  std::cout << "val: " << root->val;
  int sum = pre_sum * 10 + root->val;
  if (nullptr == root->left && nullptr == root->right) return sum;  
  return dfs(root->left, sum) + dfs(root->right, sum);
}

int sumNumbers(TreeNode* root) {
  int sum = 0;
  return dfs(root, sum);
}

int main() {
  TreeNode n0(0);
  TreeNode n1(1);
  TreeNode n5(5);
  TreeNode n9(9, &n5, &n1);
  TreeNode n4(4, &n9, &n0);
  int sum = sumNumbers(&n4);
  std::cout << "sum " << sum << "\n";
}
