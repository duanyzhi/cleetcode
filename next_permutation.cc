#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
  if (nums.empty()) return;
  if (1 == nums.size()) return;
  int size = nums.size();
  int i = size - 2;
  while (i >=0 && nums[i] >= nums[i+1]) --i;
  if (i >= 0) {
    int j = size - 1;
    while (nums[j] <= nums[i]) {
      --j;
    }
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    std::sort(nums.begin() + i + 1, nums.end());
  } else {
    std::sort(nums.begin(), nums.end());
  }
}

void print(std::vector<int>& nums) {
  for (int v : nums) {
    std::cout << v << ",";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> nums{1, 2, 3, 8, 5, 7, 6, 4};
  print(nums);
  nextPermutation(nums);
  print(nums);
}
