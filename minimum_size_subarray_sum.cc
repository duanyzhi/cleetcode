#include <iostream>
#include <vector>

int minSubArrayLen(int target, std::vector<int>& nums) {
  if (nums.empty()) return 0;
  int end = 0;
  int sum = nums[0];
  int size = nums.size() + 1;
  for (int i = 0; i < nums.size(); ++i) {
    while (sum < target && end < nums.size() - 1) {
      ++end;
      sum += nums[end];
    }
    if (sum < target && end == nums.size() - 1) break;
    size = end - i + 1 > size ? size : end - i + 1;
    std::cout << end << " " << i << " " << sum  << " " << size << "\n";
    sum -= nums[i];
  }
  return size == nums.size() + 1 ? 0 : size;
}

int main() {
  std::vector<int> nums{2,3,1,2,4,3};
  int target = 7;
  int size = minSubArrayLen(target, nums);
  std::cout << "size : " << size << "\n";
}
