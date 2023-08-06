#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
  int row = grid.size();
  int col = grid[0].size();
  grid[i][j] = '2';  // visited
  std::cout << "visited " << i << " " << j << "\n";  
  // four direction search
  if (i - 1 >= 0) {
    if ('1' == grid[i-1][j]) dfs(grid, i - 1, j);
  }
  if (i + 1 < row) {
    if ('1' == grid[i+1][j]) dfs(grid, i + 1, j);
  }
  if (j - 1 >= 0) {
    if ('1' == grid[i][j - 1]) dfs(grid, i, j - 1);
  }
  if (j + 1 < col) {
    if ('1' == grid[i][j + 1]) dfs(grid, i, j + 1);
  }
}

int numIslands(std::vector<std::vector<char>>& grid) {
  if (grid.empty()) return 0;
  int num = 0;
  for (int i =0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if ('1' == grid[i][j]) {
        num++;
        dfs(grid, i, j);
      }
    }
  }
  return num;
}

int main() {
  std::vector<std::vector<char>> grid{{'1','1','1','1','0'},
                                      {'1','1','0','1','0'},
                                      {'1','1','0','0','0'},
                                      {'0','0','0','0','0'}};
  int num = numIslands(grid);
  std::cout << "number of lands " << num;
}
