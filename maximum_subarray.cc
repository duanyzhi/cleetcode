#include <iostream>
#include <vector>

int maximum(std::vector<int>& nums) {
  std::vector<int> value(nums.size(), 0);
  value[0] = nums[0];
  int pos = 0;
  for (int i = 1; i < nums.size(); i++) {
    auto new_value = nums[i] + value[i - 1];
    if (new_value > nums[i]) {
      value[i] = new_value;
    } else {
      value[i] = nums[i];
    }
  }
  int max_value = value[0];
  for (auto v : value) {
    if (v > max_value) {
       max_value = v;
    }
  }
  return max_value;
}

int main() {
  std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
  int max_sum = maximum(nums);
  std::cout << "maximum " << max_sum << "\n";
}
