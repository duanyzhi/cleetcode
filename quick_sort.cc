#include <iostream>
#include <vector>

void print(std::vector<int>& nums) {
  for (int a : nums) {
    std::cout << a << ",";
  }
  std::cout << "\n";
}

void quick_sort(std::vector<int>& nums, int start, int end) {
  print(nums);
  std::cout << "start and end :" << start << " " << end << "\n";
  if (end < start) return;
  int base = nums[start];
  int index = start;

  int i = start;
  int j = end;
  while (i < j) {
    while (i < j && nums[j] >= base) {
      j--;
    }
    nums[i] = nums[j];
    while (i < j && nums[i] <= base) {
      i++;
    }
    nums[j] = nums[i];
    nums[i] = base;
    std::cout << i << " " << j << "\n";
  }
  quick_sort(nums, start, i - 1);
  quick_sort(nums, i + 1, end);
  print(nums);
}

int main() {
  std::vector<int> nums{3,2,1,138,34,312,0,0,1,20,9,9,1,6,4, 0};
  print(nums);
  quick_sort(nums, 0, nums.size() - 1);
}
