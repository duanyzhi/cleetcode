#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<char, std::vector<char>> map{
  {'2', {'a', 'b', 'c'}},
  {'3', {'d', 'e', 'f'}},
  {'4', {'g', 'h', 'i'}},
  {'5', {'j', 'k', 'l'}},
  {'6', {'m', 'n', 'o'}},
  {'7', {'p', 'q', 'r', 's'}},
  {'8', {'t', 'u', 'v'}},
  {'9', {'w', 'x', 'y', 'z'}}
};

std::vector<std::string> out;

void dfs(std::string digits, int index) {
  if (index >= digits.size()) {
    out.emplace_back(digits);
    return;
  }
  char key = digits[index];
  std::vector<char> values = map[key];
  for (char v : values) {
    digits[index] = v;
    std::cout << digits << "\n";
    dfs(digits, index + 1);
  }
}

std::vector<std::string> letterCombinations(std::string digits) {
  if ("" == digits) return {};
  dfs(digits, 0);
  return out;
}

int main() {
  std::string digits = "234";
  std::vector<std::string> out = letterCombinations(digits);
  for (std::string v : out) {
    std::cout << v << " ";
  }
  std::cout << "\n";
}
