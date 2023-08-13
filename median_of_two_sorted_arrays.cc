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

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
  merge(nums1, nums1.size(), nums2, nums2.size());  
  std::vector<int> all = nums1;
  int size = all.size();
  if (size % 2 == 0) {
    return (all[size / 2 - 1] + all[size / 2]) * 0.5;
  } else {
    return all[int(size / 2)];
  }
}

int main() {
  std::vector<int> nums1{1, 2};
  std::vector<int> nums2{3, 4};
  double num = findMedianSortedArrays(nums1, nums2);
  std::cout << int(11 / 2);
  std::cout << "media : " << num << "\n";
}
