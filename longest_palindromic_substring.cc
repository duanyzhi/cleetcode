#include <iostream>
#include <vector>

std::string longestPalindrome(std::string s) {
   int max_value = 0;
   int start = 0;
   int end = 0;
   for (int i = 0; i < s.size(); ++i) {
     int left = i - 1;
     int right = i + 1;
     while (left > 0 && s[left] == s[i]) {
       left--;
     }
     while (right < s.size() && s[right] == s[i]) {
       right++;
     } 
     while (left >= 0 && right < s.size() && s[left] == s[right]) {
       left--;
       right++;
     }
     std::cout << left << " " << right << "\n";
     left++;
     right--;
     if (right - left + 1 > max_value) {
        max_value = right - left + 1;
        start = left;
        end = right;
     }
   }
   return s.substr(start, end - start + 1);
}

int main() {
  // std::string s = "babad";
  std::string s = "cbbd";
  std::string palindrome = longestPalindrome(s);
  std::cout << "palindrome for " << s << " is " << palindrome << "\n";
}
