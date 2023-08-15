#include <vector>
#include <iostream>

std::string multipy(std::string num1, std::string num2) {
  if (num1.empty()) return num2;
  if (num2.empty()) return num1;
  if (num1 == "0" || num2 == "0") return "0";
  std::vector<int> out(num1.size() + num2.size(), 0);
  for (int n = 0; n < num1.size(); ++n) {
    for (int m = 0; m < num2.size(); ++m) {
      out[n+m+1] += (num1[n] - '0') * (num2[m] - '0');
    }
  }
  for (int i = num1.size() + num2.size() - 1; i > 0; --i) {
    if (out[i] >= 10) {
      out[i-1] += out[i] / 10;
      out[i] = out[i] % 10;
    }
  }
  std::string s;
  int index = out[0] == 0 ? 1 : 0;
  for (int i = index; i < out.size(); ++i) {
    s += (out[i] + '0');
  }
  return s;
}


int main() {
  std::string num1 = "123";
  std::string num2 = "456";
  std::string out = multipy(num1, num2);
  std::cout << num1 << " * " << num2 << " is " << out << "\n";
}
