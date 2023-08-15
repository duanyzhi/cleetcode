#include <iostream>
#include <vector>

int climbStairs(int n) {
  int o = 0;
  if (0 == n || 1 == n) return n;
  int n1 = 1;
  int n2 = 2;
  for (int i = 3; i <= n; ++i) {
    int new_n = n1 + n2;
    n1 = n2;
    n2 = new_n;
  }
  return n2;
}

int main() {
  int n = 10;
  int o = climbStairs(n);
  std::cout << o << "\n";
}

