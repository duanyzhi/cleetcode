#include <iostream>
#include <vector> 

int trap(std::vector<int>& height) {
  int size = height.size();
  std::vector<int> left(size, 0);
  std::vector<int> right(size, 0);
  int sum = 0;
  for (int i = 1; i < size - 1; ++i) {
    left[i] = left[i - 1] > height[i - 1] ? left[i - 1] : height[i - 1];
  }
  for (int i = size - 2; i > 0; --i) {
    right[i] = right[i + 1] > height[i + 1] ? right[i + 1] : height[i + 1];
    std::cout << i << right[i+1] << " " << height[i+1] <<  " " << right[i] << "\n";
  }
  for (int i = 1; i < size; ++i) {
    int low_height = left[i] > right[i] ? right[i] : left[i];
    std::cout << i << " " << left[i] << " " << right[i] << "\n";
    int water = low_height - height[i];
    if (water > 0) sum += water;
  }
  return sum;
}


int main() {
  std::vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
  int water = trap(height);
  std::cout << "sum is " << water;
}
