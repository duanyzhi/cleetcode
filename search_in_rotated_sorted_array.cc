#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
  if (nums.empty()) return -1;
  int end = nums.size() - 1;
  int start = 0;
  while (start < end) {
    int m = (start + end) * 0.5;
    std::cout << "middle "  << m << " " << nums[m] << "\n";
    if (nums[m] == target) return m;
    if ((nums[m] > target && (nums[start] >= target)) ||
       (nums[m] < target && (nums[end] >= target))) {
        start = m;
    } else {
        end = m;
    }
  }
  int m = (start + end) * 0.5;
  std::cout << m << " " << nums[m];
  if (nums[m] == target) return m;
  return -1;
}

int main() {
  std::vector<int> nums{4,5,6,7,0,1,2};
  // std::vector<int> nums{1, 3};
  int m = search(nums, 0);
  std::cout << m << "\n";
}
