#include <iostream>
#include <vector>

int compareVersion(std::string version1, std::string version2) {
  int i = 0, j = 0;
  while (i < version1.size() || j < version2.size()) {
     int num1 = 0;
     int num2 = 0;
     while (i < version1.size() && version1[i] != '.') 
       num1 = num1 * 10 + version1[i++] - '0';
     while (j < version2.size() && version2[j] != '.') 
       num2 = num2 * 10 + version2[j++] - '0';
     std::cout << num1 << " " << num2 << "\n";
     if (num1 > num2) return 1;
     if (num2 > num1) return -1;
     ++i; ++j;  // skip .
  }
  return 0; // same
}

int main() {
  std::string v1 = "1.01";
  std::string v2 = "1.001";
  int o = compareVersion(v1, v2);
  std::cout << v1 << " " << v2 << " " << o << "\n";
}
