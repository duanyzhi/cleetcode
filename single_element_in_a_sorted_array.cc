#include <iostream>
#include <vector>

int singleNonDuplicate(std::vector<int>& nums) {
  int value = nums[0];
  if (nums.size() == 1) return nums[0];
  int i = 1;
  while (i < nums.size()) {
    if (nums[i] == value) {
      ++i;
      if (i < nums.size()) value = nums[i];
    } else {
      return value;
    }
    ++i;
  }
  return value;
}

int main() {
  std::vector<int> nums{1,1,2,3,3,4,4,8,8};
  int out = singleNonDuplicate(nums);
  std::cout << out << "\n";
}
