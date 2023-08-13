#include <iostream>
#include <vector>

std::vector<std::string> ss;

void dfs(const std::string& s, int left, int right) {
  if (left < 0 || left > right || right < 0) {
    return;
  }
  if (left == 0 && right == 0) {
     std::cout << "end of " << s << "\n";
     ss.emplace_back(s);
     return;
  }
  dfs(s + '(', left - 1, right);
  dfs(s + ')', left, right -1);
}

std::vector<std::string> generateParenthesis(int n) {
  std::string s = "";
  dfs(s, n, n);
  return ss;
}

int main() {
  int n = 3;
  std::vector<std::string> s = generateParenthesis(n);
}
