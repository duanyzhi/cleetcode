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

std::vector<int> rightSideNodes(TreeNode* root) {
  if (nullptr == root) return {};
  TreeNode* node = root;
  std::vector<int> right_vals;
  while (nullptr != node) {
    right_vals.emplace_back(node->val);
    if (nullptr != node->right) {
      node = node->right;
      continue;
    }
    if (nullptr != node->left) {
      node = node->left;
      continue;
    }
    node = nullptr;
  }
  return right_vals;
}

std::vector<int> rightSideView(TreeNode* root) {
  if (nullptr == root) return {};
  std::vector<int> left = rightSideNodes(root->left);
  std::vector<int> right = rightSideNodes(root->right);
  if (right.size() > left.size()) {
    right.insert(right.begin(), root->val);
    return right;
  }
  for (int i = right.size(); i < left.size(); ++i) {
    right.emplace_back(left[i]);
  }
  right.insert(right.begin(), root->val);
  return right;
}

std::vector<int> dfs(TreeNode* root) {
  if (nullptr == root) return {};
  std::queue<TreeNode*> tree;
  tree.push(root);
  std::vector<int> right_vals;
  while (!tree.empty()) {
    right_vals.emplace_back(tree.back()->val);
    int level_size = tree.size();
    for (int i = 0; i < level_size; i++) {
      TreeNode* node = tree.front();
      if (nullptr != node->left) tree.push(node->left);
      if (nullptr != node->right) tree.push(node->right);
      tree.pop();
    }
  }
  return right_vals;
}

void print(std::vector<int>& vals) {
  for (auto v : vals) {
    std::cout << v << " -> ";
  }
  std::cout << "\n";
}

int main() {
  TreeNode n5(5);
  TreeNode n4(4);
  TreeNode n2(2, nullptr, &n5);
  TreeNode n3(3, nullptr, &n4);
  TreeNode n1(1, &n2, &n3);
  std::vector<int> right_vals = dfs(&n1);
  print(right_vals);

  {
    // case 1 2 3 4
    TreeNode n4(4);
    TreeNode n3(3);
    TreeNode n2(2, &n4, nullptr);
    TreeNode n1(1, &n2, &n3);
    std::vector<int> rv = dfs(&n1);
    print(rv);
  }
 
  {
    TreeNode n6(6);
    TreeNode n5(5);
    TreeNode n4(4, &n6, nullptr);
    TreeNode n3(3, &n4, &n5);
    TreeNode n2(2, nullptr, &n3);
    TreeNode n1(1, nullptr, &n2);
    std::vector<int> rv = dfs(&n1);
    print(rv);
  }
 
}
