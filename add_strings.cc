#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using IntType = long long int;

std::vector<int> str2num(std::string s) {
  std::unordered_map<char, int> map{{'0', 0}, {'1', 1},
   {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},
   {'7', 7}, {'8', 8}, {'9', 9}};
  std::vector<int> nums;
  nums.reserve(s.size());
  for (int i = s.size() - 1; i >= 0; --i) {
    nums.emplace_back(map[s[i]]);
  }
  return nums;
}

std::string addStrings(std::string num1, std::string num2) {
   std::vector<int> number1 = str2num(num1);
   std::vector<int> number2 = str2num(num2);
   int size = std::max(number1.size(), number2.size());
   int a = 0;
   std::stack<std::string> out_stack;
   for (int i = 0; i < size; ++i) {
     int sum = 0;
     if (i >= number1.size()) {
       sum = number2[i] + a;
     } else if (i >= number2.size()) {
       sum = number1[i] + a;
     } else {
       sum = number1[i] + number2[i] + a;
     }   
     int mod = sum % 10;
     if (sum >= 10) {
       a = sum / 10;
     } else {
       a = 0;
     }
     std::cout << sum << " " << mod << " " << a << "\n";
     out_stack.push(std::to_string(mod));
   }
   if (0 != a) {
     out_stack.push(std::to_string(a));
   }
   std::string s;
   while (!out_stack.empty()) {
     s += out_stack.top();
     out_stack.pop();
   }
   return s;
}

int main() {
  //std::string num1 = "11";
  //std::string num2 = "123";
  std::string num1 = "6913259244";
  std::string num2 = "71103343";
  std::string out = addStrings(num1, num2);
  std::cout << "add " << num1 << " and " << num2 << " is " << out << "\n";

}
