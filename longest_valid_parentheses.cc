#include <iostream>
#include <vector>

// ()()((()()))
int dp(std::string s) {
  std::vector<int> value(s.size(), 0);
  if ("" == s) return 0;
  for (int i = 1; i < s.size(); ++i) {
    if ('(' == s[i]) continue;
    if (')' != s[i]) continue;
    if ('(' == s[i - 1]) {   // ()
      value[i] = i - 2 > 0 ? value[i - 2] + 2 : 2;
    } else {  // (())
       // value[i - 1] is long number of s[i - 1]
       const bool valid = i - value[i - 1] - 1 >= 0;
       if (!valid) continue;
       if ('(' == s[i - value[i - 1] - 1]) {  // match (())
         // value[i - value[i - 1] - 2] if for case: () + (())
         int pre_index = i - value[i - 1] - 2;
         int pre_value = pre_index > 0 ? value[pre_index] : 0;
         value[i] = value[i - 1] + 2 + pre_value;
       }
    }
  }
  int max_value = 0;
  for (int v : value) {
    if (v > max_value) max_value = v;
  }
  return max_value;
}

int main() {
  std::vector<std::string> ss{"()()(())", "", "()", "())"};
  for (std::string s : ss) {
    int value = dp(s);
    std::cout << s << " with value " << value << "\n";
  }
  // std::cout << typeid("(") << " " << typeid('(');
}
