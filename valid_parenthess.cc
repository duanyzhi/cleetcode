#include <iostream>
#include <vector>
#include <stack>
#include <map>

bool isValid(std::string s) {
  std::stack<char> stack;  
  std::map<char, char> map{{')', '('}, {']', '['}, {'}', '{'}};
  for (int i = 0; i < s.size(); ++i) {
    if ('(' == s[i] || '{' == s[i] || '[' == s[i]) {
      stack.push(s[i]);
      continue;
    }
    if (stack.empty()) return false;
    if (map[s[i]] == stack.top()) {
        // valid
        stack.pop();
     } else {
        return false;
     }
  }
  if (!stack.empty()) return false;
  return true;
}
 
int main() {
  // std::string s = "([]){}";
  //std::string s = "(][){}";
  std::string s = "[";
  bool valid = isValid(s);
  std::cout << s << " is " << valid << "\n";
}
