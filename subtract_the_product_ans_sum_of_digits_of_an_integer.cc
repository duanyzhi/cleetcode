#include <iostream>
#include <vector>

int subtractProductAndSum(int n) {
  if (0 == n) return 0;
  int add = 0;
  int pro = 1;
  while (0 != n) {
    int mod = n % 10;
    n = n / 10;
    add += mod;
    pro *= mod;
  }
  return pro - add;
}

int main() {
  int n = 123;
  int o = subtractProductAndSum(n);
  std::cout << n << " " << o <<"\n";
}
