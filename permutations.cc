#include <iostream>
#include <vector>

std::vector<std::vector<int>> out;
std::vector<int> once;

void dfs(std::vector<int>& nums) {
  if (nums.empty()) {
    out.emplace_back(once);
    return;
  }
  for (int i = 0; i < nums.size(); ++i) {
    once.emplace_back(nums[i]);    
    std::vector<int> new_nums = nums;
    new_nums.erase(new_nums.begin() + i);
    dfs(new_nums);
    once.pop_back();
  }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
   std::vector<int> new_nums = nums;
   dfs(new_nums);
   return out;
}

void print(std::vector<int> nums) {
  for (int v : nums) {
    std::cout << v << ", ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> nums{1, 2, 3};
  std::vector<std::vector<int>> out = permute(nums);
  for (auto vs : out) {
    print(vs);
  }
}
