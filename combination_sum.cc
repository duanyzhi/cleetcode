#include <iostream>
#include <vector>

std::vector<std::vector<int>> values;
std::vector<int> cur;

void dfs(std::vector<int>& candidates, int begin, int target) {
  if (0 == target) {
    values.emplace_back(cur);
    return;
  }
  if (target < 0) return;
  for (int i = begin; i < candidates.size(); ++i) {
    cur.emplace_back(candidates[i]);
    dfs(candidates, i, target - candidates[i]);
    cur.pop_back();
  }  
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
  dfs(candidates, 0, target);
  return values;
}

int main() {
  std::vector<int> candidates{2, 3, 6, 7};
  int target = 7;
  std::vector<std::vector<int>> out = combinationSum(candidates, target);
  for (std::vector<int> value : out) {
    for (int v : value) std::cout << v << ", ";
    std::cout << "\n";
  }
}
