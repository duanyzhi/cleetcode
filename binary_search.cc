#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
   if (nums.empty()) return -1;
   int start = 0;
   int end = nums.size() - 1;
   int index = nums.size() / 2;
   while (start <= end) {
     if (nums[index] == target) return index;
     if (nums[index] > target) {
       end = index - 1;
     } else {
       start = index + 1;
     }
     index = (start + end) / 2;
     std::cout << "index " << index << " " << nums[index] << " " << start << " " << end << "\n";
   }
   return -1;
}

int main() {
  std::vector<int> nums{-1, 0, 3, 5, 9, 12};
  int target = 9;
  search(nums, target);
  {
    std::vector<int> nums{-1,0,3,5,9,12};
    int index = search(nums, 2);
    std::cout << index << "\n";
  }
}
