#include <iostream>
#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target) {
  int l = 0;
  int r = nums.size();

  while (l < r) {
    int m = (l + r) / 2;
    std::cout << l << " " << r << " " << m << "\n";
    if (nums[m] == target) {
      int i = m-1;
      int j = m+1;
      while (i >= 0 && nums[i] == target) --i;
      while (j < nums.size() && nums[j] == target) ++j;
      std::vector<int> range{++i, --j};
      return range;
    } else if (nums[m] > target) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return {-1, -1};
}

int main() {
  std::vector<int> nums{1};
  //std::vector<int> nums{5, 7, 7, 8, 8, 10};
  std::vector<int> range  = searchRange(nums, 1);
  std::cout << "range [" << range[0] << ", " << range[1] << "]\n";
}
