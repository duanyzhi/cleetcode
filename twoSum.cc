#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> map;
  map[nums[0]] = 0;
  for (int i = 1; i < nums.size(); ++i) {
    int new_value = target - nums[i];
    if (map.find(new_value) != map.end()) {  // find
      return {i, map[new_value]};
    } else {
      map[nums[i]] = i;
    }
  }
  return {};
}

int main() {
  std::vector<int> nums{2, 7, 11, 15};
  int target = 9;
  std::vector<int> out = twoSum(nums, target);
  for (int i : out) {
    std::cout << i << ", ";
  }
  std::cout << "\n";
}
