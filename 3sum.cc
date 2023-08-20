#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> nums) {
  for (int v : nums) {
    std::cout << v << ", ";
  }
  std::cout << "\n";
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  if (nums.size() < 3) return {};
  std::vector<std::vector<int>> out;
  if (nums.size() == 3) {
    if (nums[0] + nums[1] + nums[2] == 0) 
      out.emplace_back(nums);
      return out; 
  }
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    int base = nums[i];
    if (base > 0) return out;
    if (i > 0) {
      if (base == nums[i - 1]) continue;
    }
    int start = i + 1;
    int end = nums.size() - 1;
    while (start < end) {
      int sum = base + nums[start] + nums[end]; 
      std::cout << i << " " << start << " "  << end << " " << sum << "\n";
      if (sum == 0) {
        std::vector<int> match{nums[i], nums[start], nums[end]};
        out.emplace_back(match);
        while (start < end && nums[start] == nums[1+start]) {
          ++start;
        }
        while (start < end && nums[end] == nums[end-1]) {
          --end;
        }
        ++start; --end;
      } else if (sum > 0) {
        --end;
      } else {  // sum < 0
        ++start;
      }
    }
  }
  return out;
}

int main() {
  // std::vector<int> nums{0, 0, 0};
  std::vector<int> nums{-1, 0, 1, 2, -1, -4};
  print(nums);
  std::vector<std::vector<int>> out = threeSum(nums);
  std::cout << "output\n";
  for (std::vector<int> values : out) {
    print(values);
  }
}
