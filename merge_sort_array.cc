#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  if (nums1.empty()) return;
  if (nums2.empty()) return;
  int s1 = 0;
  std::vector<int> out;
  for (int i = 0; i < n; ++i) {
    while (nums1[s1] <= nums2[i] && s1 < m) {
      out.emplace_back(nums1[s1]);
      ++s1;
    }
    out.emplace_back(nums2[i]);
  }
  for (int i = s1; i < m; ++i) {
    out.emplace_back(nums1[i]);
  }
  nums1 = out;
}

void print(std::vector<int>& vec) {
  for (int v : vec) std::cout << v << ", ";
  std::cout << "\n";
}

int main() {
  std::vector<int> nums1{1, 2, 3, 0, 0, 0};
  std::vector<int> nums2{2, 5, 6};
  merge(nums1, 3, nums2, 3);
  print(nums1);
}
