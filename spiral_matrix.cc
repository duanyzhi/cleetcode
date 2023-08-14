#include <iostream>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
  std::vector<int> out;
  if (matrix.empty()) return out;
  out.reserve(matrix.size() * matrix[0].size());
  int upper = 0;
  int down = matrix.size() - 1;
  int left = 0;
  int right = matrix[0].size() - 1;
  while (true) {
    for (int l = left; l <= right; ++l) {
      // left to right
      out.emplace_back(matrix[upper][l]);
    }
    // next line
    ++upper;
    if (upper > down) break;
    // upper to down
    for (int i = upper; i <= down; ++i) {
      out.emplace_back(matrix[i][right]);
    }
    --right;
    if (right < left) break;
    // right to left
    for (int i = right; i >= left; --i) {
      out.emplace_back(matrix[down][i]);
    }
    --down;
    if (down < upper) break;
    for (int i = down; i >= upper; --i) {
      out.emplace_back(matrix[i][left]);
    }
    ++left;
    if (left > right) break;
  }
  return out;
}

int main() {
  std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<int> out = spiralOrder(matrix);
  for (int v : out) {
    std::cout << v << ", ";
  }  
  std::cout << "\n";
}
