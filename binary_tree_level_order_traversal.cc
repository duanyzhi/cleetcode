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
 
void print(std::vector<std::vector<int>>& vals) {
  for (int i = 0; i < vals.size(); ++i) {
    std::vector<int>& one_level = vals[i];
    std::cout << "level " << i << ":\n";
    for (int v : one_level) {
      std::cout << v << " -> ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::queue<TreeNode*> tree;
  tree.push(root);
  std::vector<std::vector<int>> node_vals;
  if (nullptr == root) return node_vals;
  while (!tree.empty()) {
    std::vector<int> one_level_vals;
    std::queue<TreeNode*> next_level_nodes;
    while (!tree.empty()) {
      TreeNode* cur_node = tree.front();
      one_level_vals.emplace_back(cur_node->val);
      if (nullptr != cur_node->left) next_level_nodes.push(cur_node->left);
      if (nullptr != cur_node->right) next_level_nodes.push(cur_node->right);
      tree.pop();
    }
    node_vals.emplace_back(one_level_vals);
    tree = next_level_nodes;
  }
  return node_vals;
}

int main() {
  TreeNode n5(5);
  TreeNode n4(4);
  TreeNode n2(2, nullptr, &n5);
  TreeNode n3(3, nullptr, &n4);
  TreeNode n1(1, &n2, &n3);
  std::vector<std::vector<int>> levels = levelOrder(&n1);
  print(levels);
}

