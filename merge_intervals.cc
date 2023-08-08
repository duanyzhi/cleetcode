#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<std::vector<int>>& nums) {
  for (std::vector<int> vec : nums) {
    std::cout << "[" << vec[0] << ", " << vec[1] << "] ";
  }
  std::cout << "\n";
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
   std::vector<std::vector<int>> meg;
   print(intervals);
   // std::sort(intervals.begin(), intervals.end());
   std::sort(intervals.begin(), intervals.end());
   print(intervals);
   int start = intervals[0][0];
   int end = intervals[0][1];
   for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= end) {
        end = std::max(end, intervals[i][1]);
      } else {
        std::vector<int> inter{start, end};
        meg.emplace_back(inter);  
        start = intervals[i][0];
        end = intervals[i][1];
      }
   }

   std::vector<int> inter{start, end};
   meg.emplace_back(inter);  
   return meg;
}

int main() {
  // std::vector<std::vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
  std::vector<std::vector<int>> intervals{{1,3},{4, 10}, {2,6}, {8,10},{15,18}};
  std::vector<std::vector<int>> out = merge(intervals);
  print(out);
}
