#include <iostream>
#include <vector>

const int row = 10;
const int col = 10;
int grid[row][col] = {0};

bool stop = false;
void dfs(int grid[][col], int x, int y) {
  if (stop) return;
  if ((x == row - 1) && (y == col - 1)) {
    stop = true; 
    std::cout << "(" << x << ", " << y << ")\n";
    return;
  }
  grid[x][y] = 1;
  std::cout << "(" << x << ", " << y << ") -> ";
  if (x - 1 >= 0) {
    if (grid[x-1][y] == 0) {  // not walk
       dfs(grid, x - 1, y);
    }
  }
  if (x + 1 < row) {
    if (grid[x+1][y] == 0) {  // not walk
       dfs(grid, x + 1, y);
    }
  }
  if (y - 1 >= 0) {
    if (grid[x][y - 1] == 0) {  // not walk
       dfs(grid, x, y - 1);
    }
  }
  if (y + 1 < col) {
    if (grid[x][y + 1] == 0) {  // not walk
       dfs(grid, x, y + 1);
    }
  }
}

// px and py for move direction
int px[] = {-1, 0, 1, 0};
int py[] = {0, -1, 0, 1};
 
int maze(int grid[][col]) {
  dfs(grid, 0, 0);
}

int main() {
  // (0, 0) -> (row, col)
  std::vector<int> start{0, 0};
  std::vector<int> end{9, 9};
  maze(grid);
}
