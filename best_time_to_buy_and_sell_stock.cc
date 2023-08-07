#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
  if (prices.empty()) return 0;
  int min_value = prices[0];
  std::vector<int> sells(prices.size(), 0);
  for (int i = 1; i < prices.size(); ++i) {
    sells[i] = prices[i] - min_value;
    min_value = prices[i] < min_value ? prices[i] : min_value;
  }
  int max_value = -1;
  for (int value : sells) {
    if (value > max_value) {
      max_value = value;
    }
  }
  return max_value < 0 ? 0 : max_value;
}


int main() {
  std::vector<int> prices{7,1,5,3,6,4};
  int profit = maxProfit(prices);
  std::cout << profit << "\n";
}
