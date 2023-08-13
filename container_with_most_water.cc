#include <iostream>
#include <vector>

int maxArea(std::vector<int>& height) {
  if (height.empty()) return 0;
  std::vector<int> areas(height.size(), 0);
  int i = 0;
  int j = height.size() - 1;
  while (i < j) {
    int area = (j - i) * std::min(height[i], height[j]);
    areas.emplace_back(area);
    if (height[i] < height[j]) {
      ++i;
    } else {
      --j;
    }
  }
  int max_area = 0;
  for (int a : areas) {
    if (a > max_area) {
       max_area = a;
    }
  }
  return max_area;
}

int main() {
  std::vector<int> height{1,8,6,2,5,4,8,3,7};
  int area = maxArea(height);
  std::cout << "maxArea is " << area << "\n";
}
